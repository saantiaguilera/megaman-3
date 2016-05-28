/*
 * server_Mob.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Mob.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <Dynamics/b2World.h>

#include "../../../game_engine/server_Engine.h"

Mob::Mob(unsigned int hp) : Character(hp), vulnerable(true) {
	b2BodyDef mobBodyDef;
	mobBodyDef.type = b2_dynamicBody;
	mobBodyDef.fixedRotation = true;
	// TODO: send x and y positions in constructor
	mobBodyDef.position.Set(0,0);
	// TODO: Maybe add it from the outside? when its created
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&mobBodyDef);

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

    //add foot sensor fixture
	boxShape.SetAsBox(0.3, 0.3, b2Vec2(0,-2), 0);
	boxFixtureDef.isSensor = true;
    myBody->CreateFixture(&boxFixtureDef);
}


bool Mob::isVulnerable() const {
	return vulnerable;
}

void Mob::setVulnerable(bool vulnerable) {
	this->vulnerable = vulnerable;
}

Mob::~Mob() {
}

int Mob::getObjectType() {
	return OT_MOB;
}
