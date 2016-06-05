/*
 * server_RingTosser.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_RINGTOSSER_H_
#define SERVER_MODEL_WEAPONS_SERVER_RINGTOSSER_H_

#include <Common/b2Settings.h>

#include "server_Weapon.h"

#define RING_TOSSER_MAX_AMMO 10

class RingTosser: public Weapon {
public:
	// Constructor
	RingTosser();
	// Destroyer
	virtual ~RingTosser();
	// fire weapon
	virtual void fire(float32 x, float32 y);
private:
	// Copy constructor
	RingTosser(const RingTosser&);
	// Assignment operator
	RingTosser& operator=(const RingTosser&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_RINGTOSSER_H_ */
