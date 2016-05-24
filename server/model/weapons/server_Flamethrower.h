/*
 * server_Flamethrower.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_FLAMETHROWER_H_
#define SERVER_MODEL_WEAPONS_SERVER_FLAMETHROWER_H_

#include "server_Weapon.h"

#define FLAMETHROWER_MAX_AMMO 20

class Flamethrower: public Weapon {
public:
	// Constructor
	Flamethrower();
	// Destroyer
	virtual ~Flamethrower();
	// Fire weapon
	void fire();
private:
	// Copy constructor
	Flamethrower(const Flamethrower&);
	// Assignment operator
	Flamethrower& operator=(const Flamethrower&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_FLAMETHROWER_H_ */
