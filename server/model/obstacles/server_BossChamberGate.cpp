/*
 * server_BossChamberGate.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_BossChamberGate.h"

BossChamberGate::BossChamberGate(float32 x, float32 y) : Obstacle(x, y) {}


BossChamberGate::~BossChamberGate() {
}

void BossChamberGate::haveEffectOn(Character* character) {
	// TODO: Teleport to new map
}
