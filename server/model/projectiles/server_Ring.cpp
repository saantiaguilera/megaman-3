/*
 * server_Ring.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Ring.h"

#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>

Ring::Ring(float32 x, float32 y, ORIENTATION facingPosition) : Projectile(RING_DAMAGE, Projectile::RING, x, y, facingPosition) {
	// Make it bouncy
	bouncy = true;
}


Ring::~Ring() {
}

int Ring::getTypeForSerialization() {
	return ObstacleViewTypeRing;
}

int Ring::getObjectType() {
	return OT_RING;
}
