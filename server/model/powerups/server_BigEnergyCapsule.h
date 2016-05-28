/*
 * server_BigEnergyCapsule.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_BIGENERGYCAPSULE_H_
#define SERVER_MODEL_POWERUPS_SERVER_BIGENERGYCAPSULE_H_

#include <Common/b2Settings.h>

#include "server_EnergyCapsule.h"

#define BIG_ENERGY_CAPSULE_DROP_RATE 0.05
#define BIG_ENERGY_CAPSULE_EFFECT_AMMOUNT 6

class BigEnergyCapsule: public EnergyCapsule {
public:
	BigEnergyCapsule(float32 x, float32 y);
	virtual ~BigEnergyCapsule();
private:
	// Copy constructor
	BigEnergyCapsule(const BigEnergyCapsule&);
	// Assignment operator
	BigEnergyCapsule& operator=(const BigEnergyCapsule&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_BIGENERGYCAPSULE_H_ */
