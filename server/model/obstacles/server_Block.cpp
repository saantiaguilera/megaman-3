/*
 * server_Block.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Block.h"

#include "../characters/server_Character.h"

Block::Block(float32 x, float32 y) : Obstacle(x, y) {}


Block::~Block() {
}

void Block::haveEffectOn(Character* character) {
	// Do not allow to pass
}
