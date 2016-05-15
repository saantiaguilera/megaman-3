/*
 * server_Character.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Character.h"

#include "../projectiles/server_Projectile.h"
#include "../weapons/server_Weapon.h"

Character::Character(unsigned int hp) : hp(hp), currentWeapon(NULL) {}


Character::~Character() {
	delete currentWeapon;
}

void Character::move(unsigned int x, unsigned int y) {
	myPoint.setX(x);
	myPoint.setY(y);
}

void Character::attack() {
	currentWeapon->fire();
}

unsigned int Character::getHp() const {
	return hp;
}

void Character::receiveShotFromProjectile(Projectile* projectile) {
	hp -= projectile->getDamage();
}

void Character::decreaseHp(unsigned int damage) {
	if (((int)hp - (int)damage) < 0){
		hp = 0;
	} else {
		hp -= damage;
	}
}
