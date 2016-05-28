/*
 * server_SmallEnergyCapsule.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_SmallEnergyCapsule.h"

SmallEnergyCapsule::SmallEnergyCapsule(float32 x, float32 y) :
		EnergyCapsule(SMALL_ENERGY_CAPSULE_DROP_RATE,
		SMALL_ENERGY_CAPSULE_EFFECT_AMMOUNT, x, y) {
}

SmallEnergyCapsule::~SmallEnergyCapsule() {
}

