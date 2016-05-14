/*
 * server_Bombman.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_BOMBMAN_H_
#define SERVER_MODEL_CHARACTERS_SERVER_BOMBMAN_H_

#include "../../weapons/server_Bomb.h"
#include "server_Humanoid.h"

#define BOMBMAN_INITIAL_HP 100

class Bombman: public Humanoid {
public:
	// Constructor
	Bombman() : Humanoid(BOMBMAN_INITIAL_HP) {
		currentWeapon = new Bomb();
	}
	// Destroyer
	virtual ~Bombman();
private:
	// Copy constructor
	Bombman(const Bombman&);
	// Assignment operator
	Bombman& operator=(const Bombman&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_BOMBMAN_H_ */
