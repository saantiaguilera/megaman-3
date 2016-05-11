/*
 * server_SparksCannon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_SPARKSCANNON_H_
#define SERVER_MODEL_WEAPONS_SERVER_SPARKSCANNON_H_

#include "server_Weapon.h"

#define SPARKS_CANNON_DAMAGE 4
#define SPARKS_CANNON_MAX_AMMO 15

class SparksCannon: public Weapon {
public:
	// Constructor
	SparksCannon() : Weapon(SPARKS_CANNON_DAMAGE, SPARKS_CANNON_MAX_AMMO) {}
	// Destroyer
	virtual ~SparksCannon();
private:
	// Copy constructor
	SparksCannon(const SparksCannon&);
	// Assignment operator
	SparksCannon& operator=(const SparksCannon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_SPARKSCANNON_H_ */
