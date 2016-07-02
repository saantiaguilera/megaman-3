/*
 * server_Character.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Character.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Common/b2Math.h>
#include <Common/b2Settings.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <sstream>

#include "../../game_engine/server_Engine.h"
#include "../../game_engine/server_EventContext.h"
#include "../../serializers/server_MovementSerializer.h"
#include "../weapons/server_Weapon.h"

#define CHARACTER_COLLISION_FILTERING_GROUP -1

Character::Character(unsigned int hp) :
		PhysicObject(), hp(hp), maxHp(hp), currentWeapon(NULL), readyToAttack(
				false), ticksPassed(0) {
}

Character::~Character() {
	delete currentWeapon;
}

void Character::attack() {
	float32 weaponX = getPositionX();
	float32 weaponY = getPositionY();

	//Since movements are in parents left/right, if a character needs to attack top or bottom just do it by yourself this
	//eg: fire(?, ?, OR_TOP);
	switch (facingPosition) {
		case OR_LEFT:
			weaponX = getPositionX() - getWidth();
			break;
		case OR_RIGHT:
			weaponX = getPositionX() + getWidth();
			break;
		case OR_TOP:
			weaponY = getPositionY() + getHeight();
			break;
		case OR_BOTTOM:
			weaponY = getPositionY() - (getHeight() + (1 * 0.02));
			break;
	}

	currentWeapon->fire(weaponX, weaponY, facingPosition);
}

unsigned int Character::getHp() const {
	return hp;
}

void Character::receiveShotFromProjectile(Projectile* projectile) {
	decreaseHp(projectile->getDamage());
	Engine::getInstance().getContext()->dispatchEvent(new MovementSerializer(getId(), getPositionX(), getPositionY()));
}

void Character::increaseHP(unsigned int amount) {
	// TODO: if they have a max hp validate here
	hp += amount;
}

Weapon* Character::getCurrentWeapon() const {
	return currentWeapon;
}

void Character::setCurrentWeapon(Weapon* anotherWeapon) {
	this->currentWeapon = anotherWeapon;
}

void Character::decreaseHp(float damage) {
	if (((int) hp - (int) damage) < 0) {
		hp = 0;
		Engine::getInstance().markObjectForRemoval(this);
	} else {
		hp -= damage;
	}
}

void Character::setFilteringGroup() {
	// Filter collision between megamans
	b2Filter filter = myBody->GetFixtureList()->GetFilterData();
	filter.groupIndex = CHARACTER_COLLISION_FILTERING_GROUP;
	myBody->GetFixtureList()->SetFilterData(filter);
}

bool Character::isAI() {
	return true;
}

std::string Character::getHpAsString() {
	std::stringstream ss;
	ss << getHp();
	return ss.str();
}

unsigned int Character::getMaxHp() {
	return maxHp;
}

void Character::incFootContacts() {
	++numFootContacts;
}

void Character::decFootContacts() {
	--numFootContacts;
}

void Character::addFootSensors() {
	b2PolygonShape polygonShape;
	b2FixtureDef myFixtureDef;
	// Set from the center of the body
	polygonShape.SetAsBox(getWidth() / 4, getHeight() / 4,
			b2Vec2(0, -getHeight()), 0);
	myFixtureDef.shape = &polygonShape;
	myFixtureDef.density = 1;
	myFixtureDef.isSensor = true;
	b2Fixture* footSensorFixture = myBody->CreateFixture(&myFixtureDef);
	footSensorFixture->SetUserData((void*) 3);
}
