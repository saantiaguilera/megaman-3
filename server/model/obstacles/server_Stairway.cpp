/*
 * server_Stairway.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Stairway.h"

Stairway::Stairway() : Obstacle(STAIRWAY_IS_PASSABLE) {}


Stairway::~Stairway() {
}

void Stairway::haveEffectOn(Character* character) {
	// TODO: Move up the length of the stairway or down
}
