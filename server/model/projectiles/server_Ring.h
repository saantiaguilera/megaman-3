/*
 * server_Ring.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_RING_H_
#define SERVER_MODEL_PROJECTILES_SERVER_RING_H_

#include "server_Projectile.h"

#define RING_DAMAGE 1

class Ring: public Projectile {
public:
	// Constructor
	Ring();
	// Destroyer
	virtual ~Ring();
private:
	// Copy constructor
	Ring(const Ring&);
	// Assignment operator
	Ring& operator=(const Ring&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_RING_H_ */
