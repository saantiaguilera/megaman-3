/*
 * server_Stairway.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_STAIRWAY_H_
#define SERVER_MODEL_OBSTACLES_SERVER_STAIRWAY_H_

#include "server_Obstacle.h"

#define STAIRWAY_IS_PASSABLE true

class Stairway: public Obstacle {
public:
	// Constructor
	Stairway();
	// Constructor
	virtual ~Stairway();
private:
	// Copy constructor
	Stairway(const Stairway&);
	// Assignment operator
	Stairway& operator=(const Stairway&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_STAIRWAY_H_ */
