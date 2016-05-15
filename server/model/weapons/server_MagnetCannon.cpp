/*
 * server_MagnetCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_MagnetCannon.h"

MagnetCannon::MagnetCannon() : Weapon(MAGNET_CANNON_MAX_AMMO) {}


MagnetCannon::~MagnetCannon() {
}

void MagnetCannon::fire() {
	--ammo;
}
