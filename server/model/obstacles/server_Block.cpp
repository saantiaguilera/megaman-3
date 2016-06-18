/*
 * server_Block.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Block.h"

#include <Common/b2Settings.h>
#include <iostream>

#include "../../game_engine/physics/server_PhysicObject.h"
#include "../../game_engine/server_Engine.h"
#include "../characters/humanoids/server_Megaman.h"

Block::Block(float32 x, float32 y) : Obstacle(x, y) {}

Block::~Block() {
}

void Block::handleCollisionWith(PhysicObject* objectCollidedWith) {
	// If we get hit by a projectile destroy it
	if(objectCollidedWith->getObjectType() == OT_PROJECTILE){
		std::cout << "Collided block with projectle" << std::endl;
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	} else if (objectCollidedWith->getObjectType() == OT_MEGAMAN){
//		((Megaman*)objectCollidedWith)->setUpdatable(false);
	}
}
