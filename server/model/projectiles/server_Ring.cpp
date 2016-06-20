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

void Ring::handleCollisionWith(PhysicObject* objectCollidedWith) {
	switch (facingPosition) {
		case OR_BOTTOM:
			facingPosition = OR_TOP;
			break;
		case OR_TOP:
			facingPosition = OR_BOTTOM;
			break;
		case OR_LEFT:
			facingPosition = OR_RIGHT;
			break;
		case OR_RIGHT:
			facingPosition = OR_LEFT;
			break;
		default:
			break;
	}
}
