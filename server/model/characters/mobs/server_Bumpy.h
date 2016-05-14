/*
 * server_Bumpy.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_MOBS_SERVER_BUMPY_H_
#define SERVER_MODEL_CHARACTERS_MOBS_SERVER_BUMPY_H_

#include "server_Mob.h"

#define BUMPY_INITIAL_HP 5

class Bumpy: public Mob {
public:
	// Constructor
	Bumpy() : Mob(BUMPY_INITIAL_HP) {}
	// Destroyer
	virtual ~Bumpy();
private:
	// Copy constructor
	Bumpy(const Bumpy&);
	// Assignment operator
	Bumpy& operator=(const Bumpy&);
};

#endif /* SERVER_MODEL_CHARACTERS_MOBS_SERVER_BUMPY_H_ */
