/*
 * server_Life.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_LIFE_H_
#define SERVER_MODEL_POWERUPS_SERVER_LIFE_H_

#include "server_Powerup.h"

#define LIFE_DROP_RATE 0.01
#define LIFE_EFFECT_AMOUNT 1

class Life: public Powerup {
public:
	// Constructor
	Life();
	// Destroyer
	virtual ~Life();
private:
	// Copy constructor
	Life(const Life&);
	// Assignment operator
	Life& operator=(const Life&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_LIFE_H_ */
