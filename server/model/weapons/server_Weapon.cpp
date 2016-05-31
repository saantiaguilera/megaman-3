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
	// TODO: If weapon has max ammo validate here
	ammo += ammoAmount;
}
