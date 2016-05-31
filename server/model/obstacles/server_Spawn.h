/*
 * server_Spawn.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_SPAWN_H_
#define SERVER_MODEL_OBSTACLES_SERVER_SPAWN_H_

#include <Common/b2Settings.h>

#include "server_Obstacle.h"

class Spawn: public Obstacle {
public:
	// Constructor
	Spawn(float32 x, float32 y);
	// Destroyer
	virtual ~Spawn();
	// Applies effect on character
	virtual void haveEffectOn(Character* character);
private:
	// Copy constructor
	Spawn(const Spawn&);
	// Assignment operator
	Spawn& operator=(const Spawn&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_SPAWN_H_ */
