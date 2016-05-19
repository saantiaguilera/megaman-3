/*
 * server_MobCannon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_MOBCANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_MOBCANNON_H_

#include "server_Weapon.h"
#include <limits>

#define MOB_CANNON_DAMAGE 1
#define MOB_CANNON_MAX_AMMO std::numeric_limits<unsigned int>::max()

class MobCannon: public Weapon {
public:
	// Constructor
	MobCannon();
	// Destroyer
	virtual ~MobCannon();
	// fire weapon
	void fire();
private:
	// Copy constructor
	MobCannon(const MobCannon&);
	// Assignment operator
	MobCannon& operator=(const MobCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_MOBCANNON_H_ */
