/*
 * server_EnergyCapsule.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_EnergyCapsule.h"

EnergyCapsule::EnergyCapsule(float dropRate, unsigned int effectAmount) :
		Powerup(dropRate, effectAmount) {
}

EnergyCapsule::~EnergyCapsule() {
}

