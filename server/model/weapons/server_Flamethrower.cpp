/*
 * server_Flamethrower.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_Flamethrower.h"

Flamethrower::~Flamethrower() {
}

void Flamethrower::fire() {
	--ammo;
}
