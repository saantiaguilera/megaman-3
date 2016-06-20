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
#include <Dynamics/b2Fixture.h>
#include <iostream>
#include <sstream>

#include "../../game_engine/server_Engine.h"
#include "../weapons/server_Weapon.h"

Character::Character(unsigned int hp) :
		PhysicObject(), hp(hp), maxHp(hp), currentWeapon(NULL), readyToAttack(false), ticksPassed(
				0) {
}

Character::~Character() {
	delete currentWeapon;
}

void Character::attack() {
	std::cout << "Character positions: " << getPositionX() << ", " << getPositionY() << std::endl;
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
			weaponY = getPositionY() - getHeight();
			break;
	}
	currentWeapon->fire(weaponX, weaponY, facingPosition);
}

unsigned int Character::getHp() const {
	return hp;
}

void Character::receiveShotFromProjectile(Projectile* projectile) {
	hp -= projectile->getDamage();
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
	polygonShape.SetAsBox(getWidth()/4, getHeight()/4, myBody->GetWorldCenter(), 0);
	myFixtureDef.shape = &polygonShape;
	myFixtureDef.density = 1;
	myFixtureDef.isSensor = true;
	b2Fixture* footSensorFixture = myBody->CreateFixture(&myFixtureDef);
	footSensorFixture->SetUserData((void*)3);
}
