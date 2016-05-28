/*
 * server_EnergyCapsule.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_ENERGYCAPSULE_H_
#define SERVER_MODEL_POWERUPS_SERVER_ENERGYCAPSULE_H_

#include <Common/b2Settings.h>

#include "server_Powerup.h"

// is an abstract class but currently has no methods
class EnergyCapsule: public Powerup {
public:
	// Constructor
	EnergyCapsule(float dropRate, unsigned int effectAmount, float32 x, float32 y);
	// Destroyer
	virtual ~EnergyCapsule();
	// Double dispatch method, apply effect on character
	virtual void haveEffectOn(Character* character);
private:
	// Copy constructor
	EnergyCapsule(const EnergyCapsule&);
	// Assignment operator
	EnergyCapsule& operator=(const EnergyCapsule&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_ENERGYCAPSULE_H_ */
