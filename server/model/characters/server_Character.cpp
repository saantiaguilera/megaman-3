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

void Character::receiveShotFromWeapon(Weapon* weapon) {
	hp -= weapon->getDamage();
}
