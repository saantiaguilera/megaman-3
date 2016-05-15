/*
 * server_PlasmaCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_PlasmaCannon.h"

PlasmaCannon::PlasmaCannon() : Weapon(PLASMA_CANNON_MAX_AMMO) {}


PlasmaCannon::~PlasmaCannon() {
}

void PlasmaCannon::fire() {
	--ammo;
}
