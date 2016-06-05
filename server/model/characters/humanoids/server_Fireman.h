/*
 * server_Fireman.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_FIREMAN_H_
#define SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_FIREMAN_H_

#include <Common/b2Settings.h>

#include "server_Humanoid.h"

#define FIREMAN_INITIAL_HP 160

class Fireman: public Humanoid {
public:
	// Constructor
	Fireman(float32 x, float32 y);
	// Destroyer
	virtual ~Fireman();
	// Update myself according to ticks passed
	void update();
	// Get type for serialization
	virtual int getTypeForSerialization();
private:
	// Copy constructor
	Fireman(const Fireman&);
	// Assignment operator
	Fireman& operator=(const Fireman&);
};

#endif /* SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_FIREMAN_H_ */
