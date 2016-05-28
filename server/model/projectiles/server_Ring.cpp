/*
 * server_Ring.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Ring.h"

Ring::Ring(float32 x, float32 y) : Projectile(RING_DAMAGE, Projectile::RING, x, y) {}


Ring::~Ring() {
}

