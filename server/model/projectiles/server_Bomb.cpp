/*
 * server_Bomb.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Bomb.h"

Bomb::Bomb(float32 x, float32 y) : Projectile(BOMB_DAMAGE, Projectile::BOMB, x, y) {
}

Bomb::~Bomb() {
}

int Bomb::getTypeForSerialization() {
	return ObstacleViewTypeBomb;
}

