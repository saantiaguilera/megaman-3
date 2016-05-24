/*
 * server_Block.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Block.h"

#include "../characters/server_Character.h"

Block::Block() : Obstacle(BLOCK_IS_PASSABLE) {}


Block::~Block() {
}

void Block::haveEffectOn(Character* character) {
	// Do not allow to pass
}
