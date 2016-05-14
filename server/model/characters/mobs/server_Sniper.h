/*
 * server_Sniper.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_MOBS_SERVER_SNIPER_H_
#define SERVER_MODEL_CHARACTERS_MOBS_SERVER_SNIPER_H_

#include "server_Mob.h"

#define SNIPER_INITAL_HP 5

class Sniper: public Mob {
public:
	// Constructor
	Sniper() : Mob(SNIPER_INITAL_HP) {}
	// Destroyer
	virtual ~Sniper();
private:
	// Copy constructor
	Sniper(const Sniper&);
	// Assignment operator
	Sniper& operator=(const Sniper&);
};

#endif /* SERVER_MODEL_CHARACTERS_MOBS_SERVER_SNIPER_H_ */
