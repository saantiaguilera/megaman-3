/*
 * server_BigAmmoPack.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_SERVER_BIGAMMOPACK_H_
#define SERVER_MODEL_SERVER_BIGAMMOPACK_H_

#include "server_AmmoPack.h"

#define BIG_AMMO_PACK_DROP_RATE 0.05
#define BIG_AMMO_PACK_EFFECT_AMMOUNT 6

class BigAmmoPack: public AmmoPack {
public:
	// Constructor
	BigAmmoPack() :
		AmmoPack(BIG_AMMO_PACK_DROP_RATE,
				BIG_AMMO_PACK_EFFECT_AMMOUNT) {
}
	// Destroyer
	virtual ~BigAmmoPack();
private:
	// Copy constructor
	BigAmmoPack(const BigAmmoPack&);
	// Assignment operator
	BigAmmoPack& operator=(const BigAmmoPack&);
};

#endif /* SERVER_MODEL_SERVER_BIGAMMOPACK_H_ */
