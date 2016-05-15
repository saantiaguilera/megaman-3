/*
 * server_SparksCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_SparksCannon.h"

SparksCannon::SparksCannon() : Weapon(SPARKS_CANNON_MAX_AMMO) {}


SparksCannon::~SparksCannon() {
}

void SparksCannon::fire() {
	--ammo;
}
