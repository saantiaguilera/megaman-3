/*
 * server_Megaman.cpp
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#include "server_Megaman.h"

#include "../../weapons/server_MagnetCannon.h"
#include "server_Humanoid.h"

Megaman::Megaman() : Humanoid(MEGAMAN_INITIAL_HP) {
	currentWeapon = new MagnetCannon();
}

Megaman::~Megaman() {
	// TODO Auto-generated destructor stub
}

