/*
 * server_Megaman.cpp
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#include "server_Megaman.h"

#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <string>

#include "../../../../common/common_MapConstants.h"
#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../../game_engine/server_Engine.h"
#include "../../../game_engine/server_EventContext.h"
#include "../../../game_engine/server_Player.h"
#include "../../../serializers/server_AmmoChangeSerializer.h"
#include "../../../serializers/server_HpChangeSerializer.h"
#include "../../../serializers/server_LifeChangeSerializer.h"
#include "../../../serializers/server_MovementSerializer.h"
#include "../../../server_Logger.h"
#include "../../obstacles/server_Obstacle.h"
#include "../../powerups/server_Powerup.h"
#include "../../projectiles/server_Projectile.h"
#include "../../weapons/server_PlasmaCannon.h"

#define MEGAMAN_COLLISION_FILTERING_GROUP -1

Megaman::Megaman(Player* humanOperator, float32 x, float32 y) : Humanoid(MEGAMAN_INITIAL_HP, x, y), humanOperator(humanOperator) {
	// Filter collision between megamans
	b2Filter filter = myBody->GetFixtureList()->GetFilterData();
	filter.groupIndex = MEGAMAN_COLLISION_FILTERING_GROUP;
	myBody->GetFixtureList()->SetFilterData(filter);

	currentWeapon = new PlasmaCannon();
	availableWeaponsMap[PLASMA_CANNON] = currentWeapon;

	notify();

	HpChangeSerializer* hpChangeSerializer = new HpChangeSerializer(getHp(), this);
	hpChangeSerializer->setDispatchClient(getId());
	Engine::getInstance().getContext()->dispatchEvent(hpChangeSerializer);

	AmmoChangeSerializer* ammoChangeSerializer = new AmmoChangeSerializer(getCurrentWeapon());
	ammoChangeSerializer->setDispatchClient(getId());
	Engine::getInstance().getContext()->dispatchEvent(ammoChangeSerializer);

	LifeChangeSerializer* lifeChangeSerializer = new LifeChangeSerializer(getHumanOperator()->getId(), getHumanOperator()->getLives());
	lifeChangeSerializer->setDispatchClient(getId());
	Engine::getInstance().getContext()->dispatchEvent(lifeChangeSerializer);
}

Megaman::~Megaman() {
	// Clean available weapons map
	for (std::map<int,Weapon*>::iterator it = availableWeaponsMap.begin(); it != availableWeaponsMap.end(); ++it){
		// Cause we delete the current one at the characters destructor
		if ((*it).second != currentWeapon)
			delete (*it).second;
	}
}

int Megaman::getObjectType() {
	return OT_MEGAMAN;
}

void Megaman::handleCollisionWith(PhysicObject* objectCollidedWith) {
	if(objectCollidedWith->getObjectType() == OT_PROJECTILE){
		Projectile* projectile = (Projectile*)objectCollidedWith;
		decreaseHp(projectile->getDamage());
	  Logger::getInstance().log(1, getHumanOperator()->getName() + " received shot, new hp is " + getHpAsString());
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	} else if (objectCollidedWith->getObjectType() == OT_POWERUP) {
		Powerup* powerup = (Powerup*)objectCollidedWith;
	  Logger::getInstance().log(1, getHumanOperator()->getName() + " picked a powerup");
		powerup->haveEffectOn(this);
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	} else if (objectCollidedWith->getObjectType() == OT_OBSTACLE || objectCollidedWith->getObjectType() == OT_LADDER) {
		Obstacle* obstacle = (Obstacle*)objectCollidedWith;
		obstacle->haveEffectOn(this);
	}
}

Player* Megaman::getHumanOperator() const {
	return humanOperator;
}

void Megaman::update() {
	MovementSerializer* serializer = new MovementSerializer(getId(), getPositionX(), getPositionY());
	Engine::getInstance().getContext()->dispatchEvent(serializer);
}

void Megaman::changeWeaponTo(int weaponType) {
	if (availableWeaponsMap[weaponType] != NULL)
		setCurrentWeapon(availableWeaponsMap[weaponType]);
}

void Megaman::makeWeaponAvailable(int weaponType, Weapon* newWeapon) {
	availableWeaponsMap[weaponType] = newWeapon;
}

void Megaman::handleStopCollidingWith(PhysicObject* objectCollidedWith) {
	if(objectCollidedWith->getObjectType() == OT_LADDER){
		// If we stopped colliding with the ladder then allow gravity effects
		myBody->SetGravityScale(1);
	}
}

void Megaman::decreaseHp(float damage) {
	if (((int)hp - (int)damage) < 0){
		hp = MEGAMAN_INITIAL_HP;

		getHumanOperator()->decreasePlayerLives();

		LifeChangeSerializer* lifeChangeSerializer = new LifeChangeSerializer(getHumanOperator()->getId(), getHumanOperator()->getLives());
		lifeChangeSerializer->setDispatchClient(getId());
		Engine::getInstance().getContext()->dispatchEvent(lifeChangeSerializer);
	} else hp -= damage;

	HpChangeSerializer* hpChangeSerializer = new HpChangeSerializer(getHp(), this);
	hpChangeSerializer->setDispatchClient(getId());
	Engine::getInstance().getContext()->dispatchEvent(hpChangeSerializer);
}

int Megaman::getTypeForSerialization() {
	return ObstacleViewTypeMegaman;
}
