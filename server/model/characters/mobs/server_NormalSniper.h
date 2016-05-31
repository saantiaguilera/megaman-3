/*
 * server_NormalSniper.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_MOBS_SERVER_NORMALSNIPER_H_
#define SERVER_MODEL_CHARACTERS_MOBS_SERVER_NORMALSNIPER_H_

#include <Common/b2Settings.h>

#include "server_Sniper.h"

class NormalSniper: public Sniper {
public:
	// Constructor
	NormalSniper(float32 x, float32 y);
	// Destroyer
	virtual ~NormalSniper();
	// Update myself according to ticks passed
	void update();
private:
	// Copy constructor
	NormalSniper(const NormalSniper&);
	// Assignment operator
	NormalSniper& operator=(const NormalSniper&);
};

#endif /* SERVER_MODEL_CHARACTERS_MOBS_SERVER_NORMALSNIPER_H_ */
