/*
 * server_Fireman.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_FIREMAN_H_
#define SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_FIREMAN_H_

#include "../../weapons/server_Flamethrower.h"
#include "server_Humanoid.h"

#define FIREMAN_INITIAL_HP 160

class Fireman: public Humanoid {
public:
	// Constructor
	Fireman() : Humanoid(FIREMAN_INITIAL_HP) {
		currentWeapon = new Flamethrower();
	}
	// Destroyer
	virtual ~Fireman();
private:
	// Copy constructor
	Fireman(const Fireman&);
	// Assignment operator
	Fireman& operator=(const Fireman&);
};

#endif /* SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_FIREMAN_H_ */
