/*
 * server_MagnetCannon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_MAGNETCANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_MAGNETCANNON_H_

#include "server_Weapon.h"

#define MAGNET_CANNON_MAX_AMMO 10

class MagnetCannon: public Weapon {
public:
	MagnetCannon();
	virtual ~MagnetCannon();
	// fire weapon
	void fire();
private:
	// Copy constructor
	MagnetCannon(const MagnetCannon&);
	// Assignment operator
	MagnetCannon& operator=(const MagnetCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_MAGNETCANNON_H_ */
