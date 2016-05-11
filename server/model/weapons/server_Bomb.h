/*
 * server_Bomb.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_BOMB_H_
#define SERVER_MODEL_WEAPONS_SERVER_BOMB_H_

#include "server_Weapon.h"

#define BOMB_DAMAGE 5
#define BOMB_MAX_AMMO 10

class Bomb: public Weapon {
public:
	// Constructor
	Bomb() : Weapon(BOMB_DAMAGE, BOMB_MAX_AMMO) {}
	// Destroyer
	virtual ~Bomb();
private:
	// Copy constructor
	Bomb(const Bomb&);
	// Assignment operator
	Bomb& operator=(const Bomb&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_BOMB_H_ */
