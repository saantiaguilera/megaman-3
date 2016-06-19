/*
 * server_Stairway.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Ladder.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <iostream>

#include "../../../common/common_MapConstants.h"
#include "../../game_engine/physics/server_PhysicObject.h"
#include "../characters/server_Character.h"

Ladder::Ladder(float32 x, float32 y) : Obstacle(x, y) {

	// Add shape to body
	b2PolygonShape boxShape;
	boxShape.SetAsBox(getWidth(),getHeight());

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	// We want to set ladder as sensor to allow objects to pass through it
	boxFixtureDef.isSensor = true;
	myBody->CreateFixture(&boxFixtureDef);
}


Ladder::~Ladder() {
}

void Ladder::haveEffectOn(Character* character) {
	// Allow the character to fly while in contact with the ladder
	character->getMyBody()->SetGravityScale(0);
}

void Ladder::releaseEffectOn(Character* character) {
	// Allow the character to fly while in contact with the ladder
	character->getMyBody()->SetGravityScale(1);
}

int Ladder::getObjectType() {
	return ObstacleViewTypeLadder;
}


void Ladder::handleCollisionWith(PhysicObject* objectCollidedWith) {
	int objectCollidedWithType = objectCollidedWith->getObjectType();
	if (objectCollidedWithType == OT_HUMANOID || objectCollidedWithType == OT_MEGAMAN){
		haveEffectOn((Character*) objectCollidedWith);
	}
}

void Ladder::handleStopCollidingWith(PhysicObject* objectCollidedWith) {
	int objectCollidedWithType = objectCollidedWith->getObjectType();
	if (objectCollidedWithType == OT_HUMANOID || objectCollidedWithType == OT_MEGAMAN){
		releaseEffectOn((Character*) objectCollidedWith);
	}
}
