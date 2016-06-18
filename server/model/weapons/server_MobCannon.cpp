/*
 * server_MobCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_MobCannon.h"

#include "../../game_engine/server_Engine.h"
#include "../projectiles/server_Plasma.h"

MobCannon::MobCannon() : Weapon(MOB_CANNON_MAX_AMMO) {}


MobCannon::~MobCannon() {
}

void MobCannon::fire(float32 x, float32 y, ORIENTATION facingPosition) {
	if (ammo > 0){
		--ammo;
		Engine::getInstance().markObjectForCreation(new Plasma(x, y, facingPosition));
	}
}

unsigned int MobCannon::getMaxAmmo() {
	return MOB_CANNON_MAX_AMMO;
}
