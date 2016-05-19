/*
 * server_BossChamberGate.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_BossChamberGate.h"

BossChamberGate::BossChamberGate() : Obstacle(BOSS_CHAMBER_GATE_IS_PASSABLE) {}


BossChamberGate::~BossChamberGate() {
}

void BossChamberGate::haveEffectOn(Character* character) {
	// Teleport to new map
}
