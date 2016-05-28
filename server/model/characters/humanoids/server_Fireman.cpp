/*
 * server_Fireman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Fireman.h"

#include "../../weapons/server_Flamethrower.h"

Fireman::Fireman(float32 x, float32 y) : Humanoid(FIREMAN_INITIAL_HP, x, y) {
	currentWeapon = new Flamethrower();
}

Fireman::~Fireman() {
}

