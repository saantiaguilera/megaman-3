/*
 * server_Sniper.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_MOBS_SERVER_SNIPER_H_
#define SERVER_MODEL_CHARACTERS_MOBS_SERVER_SNIPER_H_

#include <Common/b2Settings.h>

#include "server_Mob.h"

#define SNIPER_INITAL_HP 1

class Sniper: public Mob {
public:
	// Constructor
	Sniper(float32 x, float32 y);
	// Destroyer
	virtual ~Sniper();
	// Receive shot from projectile, killed when vulnerable or half hp when
	// ring or fire
	void receiveShotFromProjectile(Projectile* projectile);
	// Get type for serialization
	virtual int getTypeForSerialization() = 0;
private:
	// Copy constructor
	Sniper(const Sniper&);
	// Assignment operator
	Sniper& operator=(const Sniper&);
};

#endif /* SERVER_MODEL_CHARACTERS_MOBS_SERVER_SNIPER_H_ */
