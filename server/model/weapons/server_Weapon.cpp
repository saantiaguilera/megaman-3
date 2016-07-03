/*
 * server_Weapon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_Weapon.h"

#include "../characters/server_Character.h"

Weapon::Weapon(unsigned int ammo) : ammo(ammo) {}

Weapon::~Weapon() {
}

void Weapon::increaseAmmoBy(unsigned int ammoAmount) {
	if (ammo + ammoAmount > getMaxAmmo()){
		ammo = getMaxAmmo();
	} else {
		ammo += ammoAmount;
	}
}

unsigned int Weapon::getAmmo() const {
	return ammo;
}

bool Weapon::isSpecial() {
	return true;
}
