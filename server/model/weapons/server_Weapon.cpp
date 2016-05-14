/*
 * server_Weapon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_Weapon.h"

#include "../characters/server_Character.h"

Weapon::~Weapon() {
}

void Weapon::fire(Character* character) {
	if (ammo > 0){
		character->receiveShotFromWeapon(this);
		--ammo;
	}
}

unsigned int Weapon::getDamage() const {
	return damage;
}
