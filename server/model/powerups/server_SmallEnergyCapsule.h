/*
 * server_SmallEnergyCapsule.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_SMALLENERGYCAPSULE_H_
#define SERVER_MODEL_POWERUPS_SERVER_SMALLENERGYCAPSULE_H_

#include <Common/b2Settings.h>

#include "server_EnergyCapsule.h"

#define SMALL_ENERGY_CAPSULE_EFFECT_AMMOUNT 2

class SmallEnergyCapsule: public EnergyCapsule {
public:
	// Constructor
	SmallEnergyCapsule(float32 x, float32 y);
	// Destroyer
	virtual ~SmallEnergyCapsule();
private:
	// Copy constructor
	SmallEnergyCapsule(const SmallEnergyCapsule&);
	// Assignment operator
	SmallEnergyCapsule& operator=(const SmallEnergyCapsule&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_SMALLENERGYCAPSULE_H_ */
