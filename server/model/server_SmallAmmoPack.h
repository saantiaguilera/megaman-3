/*
 * server_SmallAmmoPack.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_SERVER_SMALLAMMOPACK_H_
#define SERVER_MODEL_SERVER_SMALLAMMOPACK_H_

#include "server_AmmoPack.h"

#define SMALL_AMMO_PACK_DROP_RATE 0.1
#define SMALL_AMMO_PACK_EFFECT_AMMOUNT 2

class SmallAmmoPack: public AmmoPack {
public:
	// Constructor
	SmallAmmoPack() :
		AmmoPack(SMALL_AMMO_PACK_DROP_RATE,
				SMALL_AMMO_PACK_EFFECT_AMMOUNT) {
}
	// Destroyer
	virtual ~SmallAmmoPack();
private:
	// Copy constructor
	SmallAmmoPack(const SmallAmmoPack&);
	// Assignment operator
	SmallAmmoPack& operator=(const SmallAmmoPack&);
};

#endif /* SERVER_MODEL_SERVER_SMALLAMMOPACK_H_ */
