/*
 * server_BossChamberGate.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_BOSSCHAMBERGATE_H_
#define SERVER_MODEL_OBSTACLES_SERVER_BOSSCHAMBERGATE_H_

#include <Common/b2Settings.h>

#include "server_Obstacle.h"

class BossChamberGate: public Obstacle {
public:
	// Constructor
	BossChamberGate(float32 x, float32 y);
	// Destroyer
	virtual ~BossChamberGate();
	// Applies effect on character
	virtual void haveEffectOn(Character* character);
	// Get the object type
	int getObjectType();
	// Handle collision
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith);
private:
	// Copy constructor
	BossChamberGate(const BossChamberGate&);
	// Assignment operator
	BossChamberGate& operator=(const BossChamberGate&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_BOSSCHAMBERGATE_H_ */
