/*
 * server_MagnetMan.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_MAGNETMAN_H_
#define SERVER_MODEL_CHARACTERS_SERVER_MAGNETMAN_H_

#include "../../weapons/server_MagnetCannon.h"
#include "server_Humanoid.h"

#define MAGNETMAN_INITIAL_HP 120

class MagnetMan: public Humanoid {
public:
	// Constructor
	MagnetMan() : Humanoid(MAGNETMAN_INITIAL_HP) {
		currentWeapon = new MagnetCannon();
	}
	// Destroyer
	virtual ~MagnetMan();
private:
	// Copy constructor
	MagnetMan(const MagnetMan&);
	// Assignment operator
	MagnetMan& operator=(const MagnetMan&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_MAGNETMAN_H_ */
