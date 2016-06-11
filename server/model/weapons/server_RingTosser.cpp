/*
 * server_RingTosser.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_RingTosser.h"

#include "../../game_engine/server_Engine.h"
#include "../projectiles/server_Ring.h"

RingTosser::RingTosser() : Weapon(RING_TOSSER_MAX_AMMO) {}



RingTosser::~RingTosser() {
}

void RingTosser::fire(float32 x, float32 y, int facingPosition) {
	if (ammo > 0){
		--ammo;
		Engine::getInstance().markObjectForCreation(new Ring(x + facingPosition, y));
	}
}

unsigned int RingTosser::getMaxAmmo() {
	return RING_TOSSER_MAX_AMMO;
}
