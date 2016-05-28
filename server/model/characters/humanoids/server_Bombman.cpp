/*
 * server_Bombman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Bombman.h"

#include "../../weapons/server_BombCannon.h"

Bombman::Bombman(float32 x, float32 y) : Humanoid(BOMBMAN_INITIAL_HP, x, y) {
	currentWeapon = new BombCannon();
}

Bombman::~Bombman() {
}

