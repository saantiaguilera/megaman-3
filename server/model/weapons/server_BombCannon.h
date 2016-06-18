/*
 * server_Bomb.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_BOMBCANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_BOMBCANNON_H_

#include <Common/b2Settings.h>

#include "server_Weapon.h"

#define BOMB_MAX_AMMO 10

class BombCannon: public Weapon {
public:
	// Constructor
	BombCannon();
	// Destroyer
	virtual ~BombCannon();
	// fire weapon
	virtual void fire(float32 x, float32 y, PhysicObject::ORIENTATION facingPosition);
	// Return max ammo of the weapon
	virtual unsigned int getMaxAmmo();
private:
	// Copy constructor
	BombCannon(const BombCannon&);
	// Assignment operator
	BombCannon& operator=(const BombCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_BOMBCANNON_H_ */
