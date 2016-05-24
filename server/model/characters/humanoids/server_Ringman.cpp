/*
 * sever_Ringman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Ringman.h"

Ringman::Ringman() : Humanoid(RINGMAN_INITIAL_HP) {
	currentWeapon = new RingTosser();
}

Ringman::~Ringman() {
}

