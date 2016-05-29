/*
 * server_EnergyCapsule.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_EnergyCapsule.h"

EnergyCapsule::EnergyCapsule(unsigned int effectAmount, float32 x, float32 y) :
		Powerup(effectAmount, x, y) {
}

EnergyCapsule::~EnergyCapsule() {
}

void EnergyCapsule::haveEffectOn(Character* character) {
	character->increaseHP(effectAmount);
}
