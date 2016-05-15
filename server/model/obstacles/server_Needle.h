/*
 * server_Needle.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_NEEDLE_H_
#define SERVER_MODEL_OBSTACLES_SERVER_NEEDLE_H_

#include "server_Obstacle.h"

#define NEEDLE_IS_PASSABLE false

class Needle: public Obstacle {
public:
	// Constructor
	Needle();
	// Destroyer
	virtual ~Needle();
	// Applies effect on character
	virtual void haveEffectOn(Character* character);
private:
	// Copy constructor
	Needle(const Needle&);
	// Assignment operator
	Needle& operator=(const Needle&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_NEEDLE_H_ */
