/*
 * server_Precipice.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_PRECIPICE_H_
#define SERVER_MODEL_OBSTACLES_SERVER_PRECIPICE_H_

#include <Common/b2Settings.h>

#include "server_Obstacle.h"

class Precipice: public Obstacle {
public:
	// Constructor
	Precipice(float32 x, float32 y);
	// Destroyer
	virtual ~Precipice();
	// Applies effect on character
	virtual void haveEffectOn(Character* character);
	// Handle collision
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith);
	// Handle end of collisions
	virtual void handleStopCollidingWith(PhysicObject* objectCollidedWith) {}
private:
	// Copy constructor
	Precipice(const Precipice&);
	// Assignment operator
	Precipice& operator=(const Precipice&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_PRECIPICE_H_ */
