/*
 * server_MagnetCannon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_MAGNETCANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_MAGNETCANNON_H_

#include <Common/b2Settings.h>

#include "server_Weapon.h"

#define MAGNET_CANNON_MAX_AMMO 10

class MagnetCannon: public Weapon {
public:
	MagnetCannon();
	virtual ~MagnetCannon();
	// fire weapon
	virtual void fire(float32 x, float32 y, int facingPosition);
	// Return max ammo of the weapon
	virtual unsigned int getMaxAmmo();
private:
	// Copy constructor
	MagnetCannon(const MagnetCannon&);
	// Assignment operator
	MagnetCannon& operator=(const MagnetCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_MAGNETCANNON_H_ */
