/*
 * server_Met.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_MOBS_SERVER_MET_H_
#define SERVER_MODEL_CHARACTERS_MOBS_SERVER_MET_H_

#include "server_Mob.h"

#include "../../weapons/server_Bomb.h"

#define MET_INITIAL_HP 10

class Met: public Mob {
public:
	// Constructor
	Met() : Mob(MET_INITIAL_HP) {}
	// Destroyer
	virtual ~Met();
	// receive shot from weapon parameter
	void receiveShotFromWeapon(Bomb* bomb);
private:
	// Copy constructor
	Met(const Met&);
	// Assignment operator
	Met& operator=(const Met&);
};

#endif /* SERVER_MODEL_CHARACTERS_MOBS_SERVER_MET_H_ */
