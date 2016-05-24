/*
 * server_EnergyCapsule.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_ENERGYCAPSULE_H_
#define SERVER_MODEL_POWERUPS_SERVER_ENERGYCAPSULE_H_

#include "server_Powerup.h"

// is an abstract class but currently has no methods
class EnergyCapsule: public Powerup {
public:
	// Constructor
	EnergyCapsule(float dropRate, unsigned int effectAmount);
	// Destroyer
	virtual ~EnergyCapsule();
private:
	// Copy constructor
	EnergyCapsule(const EnergyCapsule&);
	// Assignment operator
	EnergyCapsule& operator=(const EnergyCapsule&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_ENERGYCAPSULE_H_ */
