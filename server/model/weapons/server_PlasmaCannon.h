/*
 * server_PlasmaCannon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_PLASMACANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_PLASMACANNON_H_

#include <Common/b2Settings.h>
#include <limits>

#include "server_Weapon.h"

#define PLASMA_CANNON_DAMAGE 2
#define PLASMA_CANNON_MAX_AMMO std::numeric_limits<unsigned int>::max()

class PlasmaCannon: public Weapon {
public:
	// Constructor
	PlasmaCannon();
	// Destroyer
	virtual ~PlasmaCannon();
	// fire weapon
	virtual void fire(float32 x, float32 y);
	// Tell if the weapon is a special one
	virtual bool isSpecial();
private:
	// Copy constructor
	PlasmaCannon(const PlasmaCannon&);
	// Assignment operator
	PlasmaCannon& operator=(const PlasmaCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_PLASMACANNON_H_ */
