/*
 * server_SmallAmmoPack.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_SMALLAMMOPACK_H_
#define SERVER_MODEL_POWERUPS_SERVER_SMALLAMMOPACK_H_

#include <Common/b2Settings.h>

#include "server_AmmoPack.h"

#define SMALL_AMMO_PACK_EFFECT_AMMOUNT 2

class SmallAmmoPack: public AmmoPack {
public:
	// Constructor
	SmallAmmoPack(float32 x, float32 y);
	// Destroyer
	virtual ~SmallAmmoPack();
private:
	// Copy constructor
	SmallAmmoPack(const SmallAmmoPack&);
	// Assignment operator
	SmallAmmoPack& operator=(const SmallAmmoPack&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_SMALLAMMOPACK_H_ */
