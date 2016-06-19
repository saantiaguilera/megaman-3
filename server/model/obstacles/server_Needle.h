/*
 * server_Needle.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_NEEDLE_H_
#define SERVER_MODEL_OBSTACLES_SERVER_NEEDLE_H_

#include <Common/b2Settings.h>

#include "server_Obstacle.h"

class Needle: public Obstacle {
public:
	// Constructor
	Needle(float32 x, float32 y);
	// Destroyer
	virtual ~Needle();
	// Applies effect on character
	virtual void haveEffectOn(Character* character);
	// Handle collision
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith);
	// Get needle height
	float32 getHeight();
private:
	// Copy constructor
	Needle(const Needle&);
	// Assignment operator
	Needle& operator=(const Needle&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_NEEDLE_H_ */
