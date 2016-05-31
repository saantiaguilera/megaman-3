/*
 * server_Bumpy.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_MOBS_SERVER_BUMPY_H_
#define SERVER_MODEL_CHARACTERS_MOBS_SERVER_BUMPY_H_

#include <Common/b2Settings.h>

#include "server_Mob.h"

#define BUMPY_INITIAL_HP 1

class Bumpy: public Mob {
public:
	// Constructor
	Bumpy(float32 x, float32 y);
	// Destroyer
	virtual ~Bumpy();
	// Receive shot from weapon
	void receiveShotFromProjectile(Projectile* projectile);
	// Update myself according to ticks passed
	void update();
private:
	// Copy constructor
	Bumpy(const Bumpy&);
	// Assignment operator
	Bumpy& operator=(const Bumpy&);
};

#endif /* SERVER_MODEL_CHARACTERS_MOBS_SERVER_BUMPY_H_ */
