/*
 * server_JumpingSniper.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_MOBS_SERVER_JUMPINGSNIPER_H_
#define SERVER_MODEL_CHARACTERS_MOBS_SERVER_JUMPINGSNIPER_H_

#include <Common/b2Settings.h>

#include "server_Sniper.h"

class JumpingSniper: public Sniper {
public:
	// Constructor
	JumpingSniper(float32 x, float32 y);
	// Destroyer
	virtual ~JumpingSniper();
	// Update myself according to ticks passed
	void update();
	// Get type for serialization
	virtual int getTypeForSerialization();
private:
	// Copy constructor
	JumpingSniper(const JumpingSniper&);
	// Assignment operator
	JumpingSniper& operator=(const JumpingSniper&);
};

#endif /* SERVER_MODEL_CHARACTERS_MOBS_SERVER_JUMPINGSNIPER_H_ */
