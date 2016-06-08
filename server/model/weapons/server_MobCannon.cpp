/*
 * server_MobCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_MobCannon.h"

#include <Common/b2Settings.h>

#include "../projectiles/server_Plasma.h"

MobCannon::MobCannon() : Weapon(MOB_CANNON_MAX_AMMO) {}


MobCannon::~MobCannon() {
}

void MobCannon::fire(float32 x, float32 y) {
	if (ammo > 0){
		--ammo;
		new Plasma(x + BULLET_X_OFFSET, y);
	}
}
