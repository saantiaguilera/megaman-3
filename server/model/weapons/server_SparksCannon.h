/*
 * server_SparksCannon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_SPARKSCANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_SPARKSCANNON_H_

#include <Common/b2Settings.h>

#include "server_Weapon.h"

#define SPARKS_CANNON_MAX_AMMO 15

class SparksCannon: public Weapon {
public:
	// Constructor
	SparksCannon();
	// Destroyer
	virtual ~SparksCannon();
	// fire weapon
	virtual void fire(float32 x, float32 y, int facingPosition);
	// Return max ammo of the weapon
	virtual unsigned int getMaxAmmo();
private:
	// Copy constructor
	SparksCannon(const SparksCannon&);
	// Assignment operator
	SparksCannon& operator=(const SparksCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_SPARKSCANNON_H_ */
