/*
 * server_BigEnergyCapsule.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_BigEnergyCapsule.h"

BigEnergyCapsule::BigEnergyCapsule(float32 x, float32 y) :
EnergyCapsule(BIG_ENERGY_CAPSULE_EFFECT_AMMOUNT, x, y) {
}

BigEnergyCapsule::~BigEnergyCapsule() {
}

int BigEnergyCapsule::getTypeForSerialization() {
	return ObstacleViewTypeBigEnergyCapsule;
}

