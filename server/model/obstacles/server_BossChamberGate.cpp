/*
 * server_BossChamberGate.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_BossChamberGate.h"

#include "../../../common/common_MapConstants.h"
#include "../../game_engine/server_Engine.h"


BossChamberGate::BossChamberGate(float32 x, float32 y) : Obstacle(x, y) {}


BossChamberGate::~BossChamberGate() {
}

void BossChamberGate::haveEffectOn(Character* character) {
	Engine::getInstance().teleportToBossChamber();
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
