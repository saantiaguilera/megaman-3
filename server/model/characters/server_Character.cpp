/*
 * server_Character.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Character.h"

#include <Dynamics/b2Body.h>
#include <sstream>

#include "../../game_engine/server_Engine.h"
#include "../../serializers/server_AmmoChangeSerializer.h"
#include "../../serializers/server_HpChangeSerializer.h"
#include "../../serializers/server_ObjectDestructionSerializer.h"
#include "../projectiles/server_Projectile.h"
#include "../weapons/server_Weapon.h"

Character::Character(unsigned int hp) : hp(hp), currentWeapon(NULL), readyToAttack(false), ticksPassed(0) {}

Character::~Character() {
	delete currentWeapon;
}

void Character::attack() {
	currentWeapon->fire(myBody->GetPosition().x, myBody->GetPosition().y);
	AmmoChangeSerializer ammoChangeSerializer(currentWeapon->getAmmo(), getId());
	// TODO: Add to events queue
}

unsigned int Character::getHp() const {
	return hp;
}

void Character::receiveShotFromProjectile(Projectile* projectile) {
	hp -= projectile->getDamage();
	HpChangeSerializer hpChangeSerializer(getHp(), id);
	// TODO: Add it to the event list
}

void Character::increaseHP(unsigned int amount) {
	// TODO: if they have a max hp validate here
	hp += amount;
	HpChangeSerializer hpChangeSerializer(getHp(), id);
	// TODO: Add it to the event list
}

Weapon* Character::getCurrentWeapon() const {
	return currentWeapon;
}

void Character::setCurrentWeapon(Weapon* anotherWeapon) {
	this->currentWeapon = anotherWeapon;
}

void Character::decreaseHp(float damage) {
	if (((int)hp - (int)damage) < 0){
		hp = 0;
		Engine::getInstance().markObjectForRemoval(this);
	} else {
		hp -= damage;
		HpChangeSerializer hpChangeSerializer(getHp(), id);
		// TODO: Add it to the event list
	}
}

std::string Character::getHpAsString() {
	std::stringstream ss;
	ss << getHp();
	return ss.str();
}
