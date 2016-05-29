/*
 * server_Character.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Character.h"

#include <Dynamics/b2Body.h>
#include <sstream>

#include "../projectiles/server_Projectile.h"
#include "../weapons/server_Weapon.h"

Character::Character(unsigned int hp) : hp(hp), currentWeapon(NULL), readyToAttack(false), ticksPassed(0) {}


Character::~Character() {
	delete currentWeapon;
}

void Character::attack() {
	currentWeapon->fire(myBody->GetPosition().x, myBody->GetPosition().y);
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
	if (((int)hp - (int)damage) < 0){
		hp = 0;
	} else {
		hp -= damage;
	}
}

std::string Character::getHpAsString() {
	std::stringstream ss;
	ss << getHp();
	return ss.str();
}
