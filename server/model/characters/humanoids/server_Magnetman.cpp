/*
 * server_MagnetMan.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Magnetman.h"

MagnetMan::MagnetMan() : Humanoid(MAGNETMAN_INITIAL_HP) {
	currentWeapon = new MagnetCannon();
}

MagnetMan::~MagnetMan() {
}
