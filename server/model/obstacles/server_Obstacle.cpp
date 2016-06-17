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
#include <iostream>

#include "../../game_engine/server_Engine.h"

Obstacle::Obstacle(float32 x, float32 y) : PhysicObject() {
	b2BodyDef obstacleBodyDef;
	obstacleBodyDef.type = b2_staticBody;
	obstacleBodyDef.fixedRotation = true;
	obstacleBodyDef.position.Set(x,y);
	// TODO: Maybe add it from the outside? when its created
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&obstacleBodyDef);

	// Assign user data for callbacks
	myBody->SetUserData( this );

	// Add shape to body
	b2PolygonShape boxShape;
	std::cout << "Body size is: " << BODIES_SIZE << std::endl;
	boxShape.SetAsBox(BODIES_SIZE*BODIES_SIZE/2,BODIES_SIZE);

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);

	// Obstacles are generated when client inflates json, no need to notify
}

Obstacle::~Obstacle() {
	myBody->GetWorld()->DestroyBody(myBody);
}

int Obstacle::getObjectType() {
	return OT_OBSTACLE;
}
