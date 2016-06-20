/*
 * server_MagnetCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_MagnetCannon.h"

#include <iostream>

#include "../../game_engine/server_Engine.h"
#include "../projectiles/server_Magnet.h"

MagnetCannon::MagnetCannon() : Weapon(MAGNET_CANNON_MAX_AMMO) {}


MagnetCannon::~MagnetCannon() {
}

void MagnetCannon::fire(float32 x, float32 y, PhysicObject::ORIENTATION facingPosition) {
	if (ammo > 0){
		--ammo;
		Engine::getInstance().markObjectForCreation(new Magnet(x, y, facingPosition));
	}
}

unsigned int MagnetCannon::getMaxAmmo() {
	return MAGNET_CANNON_MAX_AMMO;
}
