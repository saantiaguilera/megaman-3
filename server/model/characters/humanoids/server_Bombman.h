/*
 * server_Bombman.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_BOMBMAN_H_
#define SERVER_MODEL_CHARACTERS_SERVER_BOMBMAN_H_

#include <Common/b2Settings.h>

#include "server_Humanoid.h"

#define BOMBMAN_INITIAL_HP 100

class Bombman: public Humanoid {
public:
	// Constructor
	Bombman(float32 x, float32 y);
	// Destroyer
	virtual ~Bombman();
private:
	// Copy constructor
	Bombman(const Bombman&);
	// Assignment operator
	Bombman& operator=(const Bombman&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_BOMBMAN_H_ */
