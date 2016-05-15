/*
 * server_MobCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_MobCannon.h"

MobCannon::MobCannon() : Weapon(MOB_CANNON_MAX_AMMO) {}


MobCannon::~MobCannon() {
}

void MobCannon::fire() {
	--ammo;
}
