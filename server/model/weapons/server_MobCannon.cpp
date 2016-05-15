/*
 * server_MobCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_MobCannon.h"

MobCannon::~MobCannon() {
}

void MobCannon::fire() {
	--ammo;
}
