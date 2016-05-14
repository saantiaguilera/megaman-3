/*
 * server_Character.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Character.h"

#include "../weapons/server_Weapon.h"

Character::~Character() {
	delete currentWeapon;
}

void Character::move(unsigned int x, unsigned int y) {
	myPoint.setX(x);
	myPoint.setY(y);
}

void Character::attack(Character* otherCharacter) {
	currentWeapon->fire(otherCharacter);
}

unsigned int Character::getHp() const {
	return hp;
}

void Character::receiveShotFromWeapon(Weapon* weapon) {
	hp -= weapon->getDamage();
}
