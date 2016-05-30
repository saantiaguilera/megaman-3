/*
 * server_Stairway.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Ladder.h"

#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>

#include "../../game_engine/physics/server_PhysicObject.h"
#include "../characters/server_Character.h"

Ladder::Ladder(float32 x, float32 y) : Obstacle(x, y) {
	// We want to set ladder as sensor to allow objects to pass through it
	myBody->GetFixtureList()->SetSensor(true);
}


Ladder::~Ladder() {
}

void Ladder::haveEffectOn(Character* character) {
	// Allow the character to fly while in contact with the ladder
	character->getMyBody()->SetGravityScale(0);
}

int Ladder::getObjectType() {
	return OT_LADDER;
}
