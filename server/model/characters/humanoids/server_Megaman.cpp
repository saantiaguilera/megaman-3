/*
 * server_Megaman.cpp
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#include "server_Megaman.h"

#include "../../weapons/server_PlasmaCannon.h"

Megaman::Megaman() : Humanoid(MEGAMAN_INITIAL_HP) {
	currentWeapon = new PlasmaCannon();
}

Megaman::~Megaman() {
}

