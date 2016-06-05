/*
 * server_Stairway.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_LADDER_H_
#define SERVER_MODEL_OBSTACLES_SERVER_LADDER_H_

#include <Common/b2Settings.h>

#include "server_Obstacle.h"

class Ladder: public Obstacle {
public:
	// Constructor
	Ladder(float32 x, float32 y);
	// Constructor
	virtual ~Ladder();
	// Applies effect on character
	virtual void haveEffectOn(Character* character);
	// Return my object type
	virtual int getObjectType();
private:
	// Copy constructor
	Ladder(const Ladder&);
	// Assignment operator
	Ladder& operator=(const Ladder&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_LADDER_H_ */
