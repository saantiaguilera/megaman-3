/*
 * server_Stairway.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_STAIRWAY_H_
#define SERVER_MODEL_OBSTACLES_SERVER_STAIRWAY_H_

#include <Common/b2Settings.h>

#include "server_Obstacle.h"

class Stairway: public Obstacle {
public:
	// Constructor
	Stairway(float32 x, float32 y);
	// Constructor
	virtual ~Stairway();
	// Applies effect on character
	virtual void haveEffectOn(Character* character);
private:
	// Copy constructor
	Stairway(const Stairway&);
	// Assignment operator
	Stairway& operator=(const Stairway&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_STAIRWAY_H_ */
