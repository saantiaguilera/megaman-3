/*
 * server_Bombman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Bombman.h"

Bombman::Bombman() : Humanoid(BOMBMAN_INITIAL_HP) {
	currentWeapon = new BombCannon();
}

Bombman::~Bombman() {
}

