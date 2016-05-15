/*
 * server_PlasmaCannon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_PLASMACANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_PLASMACANNON_H_

#include "server_Weapon.h"
#include <limits>

#define PLASMA_CANNON_DAMAGE 2
#define PLASMA_CANNON_MAX_AMMO std::numeric_limits<unsigned int>::max()

class PlasmaCannon: public Weapon {
public:
	// Constructor
	PlasmaCannon() : Weapon(PLASMA_CANNON_MAX_AMMO) {}
	// Destroyer
	virtual ~PlasmaCannon();
	// fire weapon
	void fire();
private:
	// Copy constructor
	PlasmaCannon(const PlasmaCannon&);
	// Assignment operator
	PlasmaCannon& operator=(const PlasmaCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_PLASMACANNON_H_ */
