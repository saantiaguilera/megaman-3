/*
 * server_BossChamberGate.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_BossChamberGate.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <iostream>

#include "../../../common/common_MapConstants.h"
#include "../../game_engine/physics/server_PhysicObject.h"
#include "../../game_engine/server_Engine.h"
#include "../characters/server_Character.h"


BossChamberGate::BossChamberGate(float32 x, float32 y) : Obstacle(x, y) {
	// Add shape to body
	b2PolygonShape boxShape;
	boxShape.SetAsBox(getWidth(),getHeight());

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);
}


BossChamberGate::~BossChamberGate() {
}

void BossChamberGate::haveEffectOn(Character* character) {
	Engine::getInstance().activateTeleportToBossChamber();
}

int BossChamberGate::getObjectType(){
	return ObstacleViewTypeBossChamberGate;
}

void BossChamberGate::handleCollisionWith(PhysicObject* objectCollidedWith) {
	int objectCollidedWithType = objectCollidedWith->getObjectType();
	if (objectCollidedWithType == OT_HUMANOID || objectCollidedWithType == OT_MEGAMAN){
		haveEffectOn((Character*) objectCollidedWith);
	}
}
