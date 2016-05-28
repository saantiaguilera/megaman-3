/*
 * server_Humanoid.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Humanoid.h"

#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2World.h>

#include "../../../game_engine/server_Engine.h"


Humanoid::Humanoid(unsigned int hp) : Character(hp) {
	b2BodyDef humanoidBodyDef;
	humanoidBodyDef.type = b2_dynamicBody;
	humanoidBodyDef.fixedRotation = true;
	// TODO: send x and y positions in constructor
	humanoidBodyDef.position.Set(0,0);
	// TODO: Maybe add it from the outside? when its created
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&humanoidBodyDef);

	// Assign user data for callbacks
	myBody->SetUserData( this );

	// Add shape to body
	// TODO: remove hardcoded parameters
	b2PolygonShape boxShape;
	boxShape.SetAsBox(1,1);

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);
}


Humanoid::~Humanoid() {
}

int Humanoid::getObjectType() {
	return OT_HUMANOID;
}
