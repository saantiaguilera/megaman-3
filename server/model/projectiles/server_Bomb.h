/*
 * server_Bomb.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_BOMB_H_
#define SERVER_MODEL_PROJECTILES_SERVER_BOMB_H_

#include <Common/b2Settings.h>

#include "server_Projectile.h"

#define BOMB_DAMAGE 5

class Bomb: public Projectile {
public:
	Bomb(float32 x, float32 y);
	virtual ~Bomb();
	// Get type for serialization
	virtual int getTypeForSerialization();
private:
	// Copy constructor
	Bomb(const Bomb&);
	// Assignment operator
	Bomb& operator=(const Bomb&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_BOMB_H_ */
