/*
 * server_AmmoPack.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_AMMOPACK_H_
#define SERVER_MODEL_POWERUPS_SERVER_AMMOPACK_H_

#include <Common/b2Settings.h>

#include "server_Powerup.h"

// Abstract class, still no methods
class AmmoPack: public Powerup {
public:
	// Constructor
	AmmoPack(float dropRate, unsigned int effectAmount, float32 x, float32 y);
	// Destroyer
	virtual ~AmmoPack();
	// Double dispatch method, apply effect on character
	virtual void haveEffectOn(Character* character);

private:
	// Copy constructor
	AmmoPack(const AmmoPack&);
	// Assignment operator
	AmmoPack& operator=(const AmmoPack&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_AMMOPACK_H_ */
