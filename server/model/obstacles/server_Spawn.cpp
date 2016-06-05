/*
 * server_Spawn.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Spawn.h"

Spawn::Spawn(float32 x, float32 y) : Obstacle(x, y) {}


Spawn::~Spawn() {
}

void Spawn::haveEffectOn(Character* character) {
}
