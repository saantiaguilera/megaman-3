/*
 * server_Obstacle.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Obstacle.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <Dynamics/b2World.h>

#include "../../game_engine/server_Engine.h"

Obstacle::Obstacle(bool passable) : passable(passable) {
	b2BodyDef obstacleBodyDef;
	obstacleBodyDef.type = b2_staticBody;
	obstacleBodyDef.fixedRotation = true;
	// TODO: send x and y positions in constructor
	obstacleBodyDef.position.Set(0,0);
	// TODO: Maybe add it from the outside? when its created
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&obstacleBodyDef);

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


bool Obstacle::isPassable() const {
	return passable;
}

Obstacle::~Obstacle() {
}

int Obstacle::getObjectType() {
	return OT_OBSTACLE;
}
