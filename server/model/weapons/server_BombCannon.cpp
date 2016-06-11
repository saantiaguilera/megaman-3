/*
 * server_Bomb.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_BombCannon.h"

#include "../projectiles/server_Bomb.h"

BombCannon::BombCannon() : Weapon(BOMB_MAX_AMMO) {}


BombCannon::~BombCannon() {
}

void BombCannon::fire(float32 x, float32 y, int facingPosition) {
	if (ammo > 0){
		--ammo;
		new Bomb(x + facingPosition, y);
	}
}

unsigned int BombCannon::getMaxAmmo() {
	return BOMB_MAX_AMMO;
}
