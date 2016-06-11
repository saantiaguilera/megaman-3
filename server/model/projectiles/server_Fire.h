/*
 * server_Fire.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_FIRE_H_
#define SERVER_MODEL_PROJECTILES_SERVER_FIRE_H_

#include <Common/b2Settings.h>

#include "server_Projectile.h"

#define FIRE_DAMAGE 6


class Fire: public Projectile {
public:
	Fire(float32 x, float32 y, int facingPosition);
	virtual ~Fire();
	// Get type for serialization
	virtual int getTypeForSerialization();
private:
	// Copy constructor
	Fire(const Fire&);
	// Assignment operator
	Fire& operator=(const Fire&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_FIRE_H_ */
