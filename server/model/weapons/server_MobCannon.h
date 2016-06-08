/*
 * server_MobCannon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_MOBCANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_MOBCANNON_H_

#include <Common/b2Settings.h>
#include <limits>

#include "server_Weapon.h"

#define MOB_CANNON_DAMAGE 1
#define MOB_CANNON_MAX_AMMO std::numeric_limits<unsigned int>::max()

class MobCannon: public Weapon {
public:
	// Constructor
	MobCannon();
	// Destroyer
	virtual ~MobCannon();
	// fire weapon
	virtual void fire(float32 x, float32 y);
	// Return max ammo of the weapon
	virtual unsigned int getMaxAmmo();
private:
	// Copy constructor
	MobCannon(const MobCannon&);
	// Assignment operator
	MobCannon& operator=(const MobCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_MOBCANNON_H_ */
