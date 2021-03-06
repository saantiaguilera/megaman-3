/*
 * server_Mob.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Mob.h"

#include <Collision/Shapes/b2CircleShape.h>
#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <Dynamics/b2World.h>
#include <vector>

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../../game_engine/server_Engine.h"
#include "../../../game_engine/server_LootGenerator.h"
#include "../../projectiles/server_Projectile.h"
#include "../../weapons/server_MobCannon.h"

Mob::Mob(unsigned int hp, float32 x, float32 y) :
		Character(hp), vulnerable(true) {
	b2BodyDef mobBodyDef;
	mobBodyDef.type = b2_dynamicBody;
	mobBodyDef.fixedRotation = true;
	mobBodyDef.position.Set(x, y);
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&mobBodyDef);

	// Assign user data for callbacks
	myBody->SetUserData(this);

	// Add shape to body
//	b2PolygonShape boxShape;
//	boxShape.SetAsBox(BODIES_SIZE,BODIES_SIZE);
	b2CircleShape circleShape;
	circleShape.m_radius = getWidth();

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &circleShape;
	boxFixtureDef.density = 40;
	myBody->CreateFixture(&boxFixtureDef);

	setFilteringGroup();

	currentWeapon = new MobCannon();

	// Add to updatables list
	Engine::getInstance().getUpdatablesList()->push_back(this);
	setUpdatable(true);
}

float32 Mob::getWidth() {
	return BODIES_SIZE;
}

float32 Mob::getHeight() {
	return BODIES_SIZE;
}

bool Mob::isVulnerable() const {
	return vulnerable;
}

void Mob::setVulnerable(bool vulnerable) {
	this->vulnerable = vulnerable;
}

Mob::~Mob() {
	LootGenerator lootGenerator;
	lootGenerator.generateLootAt(getPositionX(), getPositionY() - getHeight());
	Engine::getInstance().getMyWorld()->DestroyBody(getMyBody());
}

int Mob::getObjectType() {
	return OT_MOB;
}

void Mob::move(unsigned int moveState) {
	int oldX = getPositionX();
	int oldY = getPositionY();

	PhysicObject::move(moveState);

	if (oldX == getPositionX() && oldY == getPositionY() && isUpdatable())
		setUpdatable(false);
}

void Mob::handleCollisionWith(PhysicObject* objectCollidedWith) {
	if (objectCollidedWith->getObjectType() == OT_PROJECTILE) {
		Projectile* projectile = (Projectile*) objectCollidedWith;
		receiveShotFromProjectile(projectile);
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	}
}
