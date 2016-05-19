/*
 * server_Bomb.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_BombCannon.h"

BombCannon::BombCannon() : Weapon(BOMB_MAX_AMMO) {}


BombCannon::~BombCannon() {
}

void BombCannon::fire() {
	--ammo;
}
