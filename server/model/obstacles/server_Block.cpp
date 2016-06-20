/*
 * server_Block.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Block.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Common/b2Settings.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>

#include "../../game_engine/physics/server_PhysicObject.h"
#include "../../game_engine/server_Engine.h"

Block::Block(float32 x, float32 y) : Obstacle(x, y) {
	// Add shape to body
	b2PolygonShape boxShape;
	boxShape.SetAsBox(getWidth(),getHeight());

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);
}

Block::~Block() {
}

void Block::handleCollisionWith(PhysicObject* objectCollidedWith) {
	// If we get hit by a projectile destroy it
	if (objectCollidedWith->getObjectType() == OT_PROJECTILE && objectCollidedWith->getObjectType() != OT_RING){
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	}
}
