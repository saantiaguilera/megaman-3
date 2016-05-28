/*
 * server_EnergyCapsule.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_EnergyCapsule.h"

EnergyCapsule::EnergyCapsule(float dropRate, unsigned int effectAmount, float32 x, float32 y) :
		Powerup(dropRate, effectAmount, x, y) {
}

EnergyCapsule::~EnergyCapsule() {
}

