/*
 * server_RingTosser.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_RingTosser.h"

#include "../projectiles/server_Ring.h"

RingTosser::RingTosser() : Weapon(RING_TOSSER_MAX_AMMO) {}



RingTosser::~RingTosser() {
}

void RingTosser::fire(float32 x, float32 y) {
	if (ammo > 0){
		--ammo;
		new Ring(x + BULLET_X_OFFSET, y);
	}
}

unsigned int RingTosser::getMaxAmmo() {
	return RING_TOSSER_MAX_AMMO;
}
