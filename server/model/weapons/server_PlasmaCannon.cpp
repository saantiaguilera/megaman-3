/*
 * server_PlasmaCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_PlasmaCannon.h"

#include "../../game_engine/server_Engine.h"
#include "../projectiles/server_Plasma.h"

PlasmaCannon::PlasmaCannon() : Weapon(PLASMA_CANNON_MAX_AMMO) {}


PlasmaCannon::~PlasmaCannon() {
}

void PlasmaCannon::fire(float32 x, float32 y, int facingPosition) {
	if (ammo > 0){
		--ammo;
		Engine::getInstance().markObjectForCreation(new Plasma(x + facingPosition, y));
	}
}

bool PlasmaCannon::isSpecial() {
	return false;
}

unsigned int PlasmaCannon::getMaxAmmo() {
	return PLASMA_CANNON_MAX_AMMO;
}
