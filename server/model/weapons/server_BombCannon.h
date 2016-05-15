/*
 * server_Bomb.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_BOMBCANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_BOMBCANNON_H_

#include "server_Weapon.h"

#define BOMB_MAX_AMMO 10

class BombCannon: public Weapon {
public:
	// Constructor
	BombCannon() : Weapon(BOMB_MAX_AMMO) {}
	// Destroyer
	virtual ~BombCannon();
	// fire weapon
	void fire();
private:
	// Copy constructor
	BombCannon(const BombCannon&);
	// Assignment operator
	BombCannon& operator=(const BombCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_BOMBCANNON_H_ */
