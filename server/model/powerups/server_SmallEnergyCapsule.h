/*
 * server_SmallEnergyCapsule.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_SMALLENERGYCAPSULE_H_
#define SERVER_MODEL_POWERUPS_SERVER_SMALLENERGYCAPSULE_H_

#include "server_EnergyCapsule.h"

#define SMALL_ENERGY_CAPSULE_DROP_RATE 0.1
#define SMALL_ENERGY_CAPSULE_EFFECT_AMMOUNT 2

class SmallEnergyCapsule: public EnergyCapsule {
public:
	// Constructor
	SmallEnergyCapsule() :
			EnergyCapsule(SMALL_ENERGY_CAPSULE_DROP_RATE,
					SMALL_ENERGY_CAPSULE_EFFECT_AMMOUNT) {
	}
	// Destroyer
	virtual ~SmallEnergyCapsule();
private:
	// Copy constructor
	SmallEnergyCapsule(const SmallEnergyCapsule&);
	// Assignment operator
	SmallEnergyCapsule& operator=(const SmallEnergyCapsule&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_SMALLENERGYCAPSULE_H_ */
