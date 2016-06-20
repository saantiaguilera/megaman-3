/*
 * server_Bomb.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_BombCannon.h"

#include <iostream>

#include "../../game_engine/server_Engine.h"
#include "../projectiles/server_Bomb.h"

BombCannon::BombCannon() : Weapon(BOMB_MAX_AMMO) {}


BombCannon::~BombCannon() {
}

void BombCannon::fire(float32 x, float32 y, PhysicObject::ORIENTATION facingPosition) {
	if (ammo > 0){
		--ammo;
		Bomb* aBomb = new Bomb(x, y, facingPosition);
		Engine::getInstance().markObjectForCreation(aBomb);
	}
}

unsigned int BombCannon::getMaxAmmo() {
	return BOMB_MAX_AMMO;
}
