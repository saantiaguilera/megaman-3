/*
 * server_Needle.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Needle.h"

#include "../characters/server_Character.h"

Needle::Needle(float32 x, float32 y) : Obstacle(x, y) {}


Needle::~Needle() {
}

void Needle::haveEffectOn(Character* character) {
	character->decreaseHp(character->getHp());
}
