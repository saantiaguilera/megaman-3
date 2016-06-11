/*
 * server_Bomb.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Bomb.h"

Bomb::Bomb(float32 x, float32 y, int facingPosition) : Projectile(BOMB_DAMAGE, Projectile::BOMB, x, y, facingPosition) {
}

Bomb::~Bomb() {
}

int Bomb::getTypeForSerialization() {
	return ObstacleViewTypeBomb;
}

