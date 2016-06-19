/*
 * server_Needle.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Needle.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>

#include "../../game_engine/physics/server_PhysicObject.h"
#include "../characters/server_Character.h"

Needle::Needle(float32 x, float32 y) : Obstacle(x, y) {
	// Add shape to body
	b2PolygonShape boxShape;
	boxShape.SetAsBox(getWidth(),getHeight());

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);
}


Needle::~Needle() {
}

void Needle::haveEffectOn(Character* character) {
	character->decreaseHp(character->getHp());
}

void Needle::handleCollisionWith(PhysicObject* objectCollidedWith) {
	int objectCollidedWithType = objectCollidedWith->getObjectType();
	if (objectCollidedWithType == OT_HUMANOID || objectCollidedWithType == OT_MEGAMAN){
		haveEffectOn((Character*) objectCollidedWith);
	}
}

float32 Needle::getHeight() {
	return BODIES_SIZE/20;
}

