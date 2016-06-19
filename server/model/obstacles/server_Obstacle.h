/*
 * server_Obstacle.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_OBSTACLE_H_
#define SERVER_MODEL_OBSTACLES_SERVER_OBSTACLE_H_

#include <Common/b2Settings.h>

#include "../../game_engine/physics/server_PhysicObject.h"
#include "../characters/server_Character.h"

class Obstacle : public PhysicObject {
public:
	// Constructor
	Obstacle(float32 x, float32 y);
	// Destroyer
	virtual ~Obstacle();
	// Applies its effect on character
	virtual void haveEffectOn(Character* character) {}
	// Return object type
	virtual int getObjectType();
	// Get type for serialization
	virtual int getTypeForSerialization() { return 0; }
	// Handle collisions
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith) = 0;
	// Return width
	virtual float32 getWidth();
	// Return height
	virtual float32 getHeight();
private:
	// Copy constructor
	Obstacle(const Obstacle&);
	// Assignment operator
	Obstacle& operator=(const Obstacle&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_OBSTACLE_H_ */
