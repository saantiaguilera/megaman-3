/*
 * server_Powerup.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_Powerup.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <Dynamics/b2World.h>

#include "../../game_engine/server_Engine.h"


Powerup::Powerup(float dropRate, unsigned int effectAmount, float32 x, float32 y) :
		dropRate(dropRate), effectAmount(effectAmount) {
	// TODO: Use sensors for powerups picking and field of view
	b2BodyDef powerupBodyDef;
	powerupBodyDef.type = b2_staticBody;
	// TODO: send x and y positions in constructor
	powerupBodyDef.position.Set(x,y);
	// TODO: Maybe add it from the outside? when its created
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&powerupBodyDef);

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

Powerup::~Powerup() {
}

int Powerup::getObjectType() {
	return OT_POWERUP;
}
