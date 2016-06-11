/*
 * server_Flamethrower.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_Flamethrower.h"

#include "../../game_engine/server_Engine.h"
#include "../projectiles/server_Fire.h"

Flamethrower::Flamethrower() : Weapon(FLAMETHROWER_MAX_AMMO) {}


Flamethrower::~Flamethrower() {
}

void Flamethrower::fire(float32 x, float32 y, int facingPosition) {
	if (ammo > 0){
		--ammo;
		Engine::getInstance().markObjectForCreation(new Fire(x + facingPosition, y));
	}
}

unsigned int Flamethrower::getMaxAmmo() {
	return FLAMETHROWER_MAX_AMMO;
}
