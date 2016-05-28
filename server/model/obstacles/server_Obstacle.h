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

class Character;

class Obstacle : public PhysicObject {
public:
	// Constructor
	Obstacle(float32 x, float32 y);
	// Destroyer
	virtual ~Obstacle();
	// Applies its effect on character
	virtual void haveEffectOn(Character* character) = 0;
	// Return object type
	virtual int getObjectType();
private:
	// Copy constructor
	Obstacle(const Obstacle&);
	// Assignment operator
	Obstacle& operator=(const Obstacle&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_OBSTACLE_H_ */
