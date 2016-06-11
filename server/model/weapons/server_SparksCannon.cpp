/*
 * server_SparksCannon.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_SparksCannon.h"

#include "../projectiles/server_Spark.h"

SparksCannon::SparksCannon() : Weapon(SPARKS_CANNON_MAX_AMMO) {}


SparksCannon::~SparksCannon() {
}

void SparksCannon::fire(float32 x, float32 y, int facingPosition) {
	if (ammo > 0){
		--ammo;
		new Spark(x + facingPosition, y);
	}
}

unsigned int SparksCannon::getMaxAmmo() {
	return SPARKS_CANNON_MAX_AMMO;
}
