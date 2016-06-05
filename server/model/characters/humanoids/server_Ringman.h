/*
 * server_Ringman.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_RINGMAN_H_
#define SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_RINGMAN_H_

#include <Common/b2Settings.h>

#include "server_Humanoid.h"

#define RINGMAN_INITIAL_HP 100

class Ringman: public Humanoid {
public:
	// Constructor
	Ringman(float32 x, float32 y);
	// Destroyer
	virtual ~Ringman();
	// Update myself according to ticks passed
	void update();
	// Get type for serialization
	virtual int getTypeForSerialization();
private:
	// Copy constructor
	Ringman(const Ringman&);
	// Assignment operator
	Ringman& operator=(const Ringman&);
};

#endif /* SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_RINGMAN_H_ */
