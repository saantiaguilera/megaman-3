/*
 * server_Flamethrower.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_FLAMETHROWER_H_
#define SERVER_MODEL_WEAPONS_SERVER_FLAMETHROWER_H_

#include "server_Weapon.h"

#define FLAMETHROWER_DAMAGE 6
#define FLAMETHROWER_MAX_AMMO 20

class Flamethrower: public Weapon {
public:
	// Constructor
	Flamethrower() : Weapon(FLAMETHROWER_DAMAGE, FLAMETHROWER_MAX_AMMO) {}
	// Destroyer
	virtual ~Flamethrower();
private:
	// Copy constructor
	Flamethrower(const Flamethrower&);
	// Assignment operator
	Flamethrower& operator=(const Flamethrower&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_FLAMETHROWER_H_ */
