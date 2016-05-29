/*
 * server_MagnetMan.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_MAGNETMAN_H_
#define SERVER_MODEL_CHARACTERS_SERVER_MAGNETMAN_H_

#include <Common/b2Settings.h>

#include "server_Humanoid.h"

#define MAGNETMAN_INITIAL_HP 120

class MagnetMan: public Humanoid {
public:
	// Constructor
	MagnetMan(float32 x, float32 y);
	// Destroyer
	virtual ~MagnetMan();
	// Update myself according to ticks passed
	void update();
private:
	// Copy constructor
	MagnetMan(const MagnetMan&);
	// Assignment operator
	MagnetMan& operator=(const MagnetMan&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_MAGNETMAN_H_ */
