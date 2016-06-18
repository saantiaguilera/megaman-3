/*
 * server_Character.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Character.h"

#include <iostream>
#include <list>
#include <sstream>

#include "../../game_engine/server_Engine.h"
#include "../../game_engine/server_EventContext.h"
#include "../../serializers/server_AmmoChangeSerializer.h"
#include "../../serializers/server_HpChangeSerializer.h"
#include "../projectiles/server_Projectile.h"
#include "../weapons/server_Weapon.h"

Character::Character(unsigned int hp) :
		PhysicObject(), hp(hp), currentWeapon(NULL), readyToAttack(false), ticksPassed(
				0), maxHp(hp) {
}

Character::~Character() {
	delete currentWeapon;
}

void Character::attack() {
	std::cout << getPositionX() << ", " << getPositionY() << std::endl;
	currentWeapon->fire(getPositionX(), getPositionY(), facingPosition);
	AmmoChangeSerializer* ammoChangeSerializer = new AmmoChangeSerializer(
			currentWeapon);
	ammoChangeSerializer->setDispatchClient(getId());
	Engine::getInstance().getContext()->dispatchEvent(ammoChangeSerializer);
}

unsigned int Character::getHp() const {
	return hp;
}

void Character::receiveShotFromProjectile(Projectile* projectile) {
	hp -= projectile->getDamage();
	HpChangeSerializer *hpChangeSerializer = new HpChangeSerializer(getHp(), this);
	hpChangeSerializer->setDispatchClient(getId());
	Engine::getInstance().getContext()->dispatchEvent(hpChangeSerializer);
}

void Character::increaseHP(unsigned int amount) {
	// TODO: if they have a max hp validate here
	hp += amount;
	HpChangeSerializer *hpChangeSerializer = new HpChangeSerializer(getHp(), this);
	hpChangeSerializer->setDispatchClient(getId());
	Engine::getInstance().getContext()->dispatchEvent(hpChangeSerializer);
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
		HpChangeSerializer *hpChangeSerializer = new HpChangeSerializer(getHp(), this);
		hpChangeSerializer->setDispatchClient(getId());
		Engine::getInstance().getContext()->dispatchEvent(hpChangeSerializer);
	}
}

std::string Character::getHpAsString() {
	std::stringstream ss;
	ss << getHp();
	return ss.str();
}

unsigned int Character::getMaxHp() {
	return maxHp;
}
