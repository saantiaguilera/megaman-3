/*
 * sever_Ringman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Ringman.h"

#include "../../weapons/server_RingTosser.h"

Ringman::Ringman(float32 x, float32 y) : Humanoid(RINGMAN_INITIAL_HP, x, y) {
	currentWeapon = new RingTosser();
}

Ringman::~Ringman() {
}

