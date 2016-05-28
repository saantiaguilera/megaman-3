/*
 * server_Stairway.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Stairway.h"

Stairway::Stairway(float32 x, float32 y) : Obstacle(x, y) {}


Stairway::~Stairway() {
}

void Stairway::haveEffectOn(Character* character) {
	// TODO: Move up the length of the stairway or down
}
