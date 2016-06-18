/*
 * server_Plasma.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_PLASMA_H_
#define SERVER_MODEL_PROJECTILES_SERVER_PLASMA_H_

#include <Common/b2Settings.h>

#include "server_Projectile.h"

#define PLASMA_DAMAGE 1

class Plasma: public Projectile {
public:
	// Constructor
	Plasma(float32 x, float32 y, ORIENTATION facingPosition);
	// Destroyer
	virtual ~Plasma();
	// Get type for serialization
	virtual int getTypeForSerialization();
private:
	// Copy constructor
	Plasma(const Plasma&);
	// Assignment operator
	Plasma& operator=(const Plasma&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_PLASMA_H_ */
