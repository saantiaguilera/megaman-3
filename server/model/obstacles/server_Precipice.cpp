/*
 * server_Precipice.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Precipice.h"

#include "../characters/server_Character.h"

Precipice::Precipice(float32 x, float32 y) : Obstacle(x, y) {}


Precipice::~Precipice() {
}

void Precipice::haveEffectOn(Character* character) {
	character->decreaseHp(character->getHp());
}

void Precipice::handleCollisionWith(PhysicObject* objectCollidedWith) {
	int objectCollidedWithType = objectCollidedWith->getObjectType();
	if (objectCollidedWithType == OT_HUMANOID || objectCollidedWithType == OT_MEGAMAN || objectCollidedWithType == OT_MOB){
		haveEffectOn((Character*) objectCollidedWith);
	}
}
