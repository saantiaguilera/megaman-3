/*
 * server_Ring.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_RING_H_
#define SERVER_MODEL_PROJECTILES_SERVER_RING_H_

#include <Common/b2Settings.h>

#include "server_Projectile.h"

#define RING_DAMAGE 1

// Should bounce against walls

class Ring: public Projectile {
public:
	// Constructor
	Ring(float32 x, float32 y, int facingPosition);
	// Destroyer
	virtual ~Ring();
	// Get type for serialization
	virtual int getTypeForSerialization();
private:
	// Copy constructor
	Ring(const Ring&);
	// Assignment operator
	Ring& operator=(const Ring&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_RING_H_ */
