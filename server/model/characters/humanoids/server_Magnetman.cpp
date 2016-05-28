/*
 * server_MagnetMan.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Magnetman.h"

#include "../../weapons/server_MagnetCannon.h"

MagnetMan::MagnetMan(float32 x, float32 y) : Humanoid(MAGNETMAN_INITIAL_HP, x, y) {
	currentWeapon = new MagnetCannon();
}

MagnetMan::~MagnetMan() {
}
