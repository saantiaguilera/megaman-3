/*
 * server_BigEnergyCapsule.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_SERVER_BIGENERGYCAPSULE_H_
#define SERVER_MODEL_SERVER_BIGENERGYCAPSULE_H_

#include "server_EnergyCapsule.h"

#define BIG_ENERGY_CAPSULE_DROP_RATE 0.05
#define BIG_ENERGY_CAPSULE_EFFECT_AMMOUNT 6

class BigEnergyCapsule: public EnergyCapsule {
public:
	BigEnergyCapsule() :
	EnergyCapsule(BIG_ENERGY_CAPSULE_DROP_RATE,
			BIG_ENERGY_CAPSULE_EFFECT_AMMOUNT) {
};
	virtual ~BigEnergyCapsule();
private:
	// Copy constructor
	BigEnergyCapsule(const BigEnergyCapsule&);
	// Assignment operator
	BigEnergyCapsule& operator=(const BigEnergyCapsule&);
};

#endif /* SERVER_MODEL_SERVER_BIGENERGYCAPSULE_H_ */
