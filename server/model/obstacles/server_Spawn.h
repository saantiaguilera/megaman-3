/*
 * server_Spawn.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_SPAWN_H_
#define SERVER_MODEL_OBSTACLES_SERVER_SPAWN_H_

#include "server_Obstacle.h"

#define SPAWN_IS_PASSABLE true

class Spawn: public Obstacle {
public:
	// Constructor
	Spawn() : Obstacle(SPAWN_IS_PASSABLE) {}
	// Destroyer
	virtual ~Spawn();
private:
	// Copy constructor
	Spawn(const Spawn&);
	// Assignment operator
	Spawn& operator=(const Spawn&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_SPAWN_H_ */
