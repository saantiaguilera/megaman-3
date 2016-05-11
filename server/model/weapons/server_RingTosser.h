/*
 * server_RingTosser.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_RINGTOSSER_H_
#define SERVER_MODEL_WEAPONS_SERVER_RINGTOSSER_H_

#include "server_Weapon.h"

#define RING_TOSSER_DAMAGE 3
#define RING_TOSSER_MAX_AMMO 10

class RingTosser: public Weapon {
public:
	// Constructor
	RingTosser() : Weapon(RING_TOSSER_DAMAGE, RING_TOSSER_MAX_AMMO) {}
	// Destroyer
	virtual ~RingTosser();
private:
	// Copy constructor
	RingTosser(const RingTosser&);
	// Assignment operator
	RingTosser& operator=(const RingTosser&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_RINGTOSSER_H_ */
