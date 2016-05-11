/*
 * server_AmmoPack.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_AMMOPACK_H_
#define SERVER_MODEL_POWERUPS_SERVER_AMMOPACK_H_

#include "server_Powerup.h"

// Abstract class, still no methods
class AmmoPack: public Powerup {
public:
	AmmoPack(float dropRate, unsigned int effectAmount) :
		Powerup(dropRate, effectAmount) {
}
	virtual ~AmmoPack();
private:
	// Copy constructor
	AmmoPack(const AmmoPack&);
	// Assignment operator
	AmmoPack& operator=(const AmmoPack&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_AMMOPACK_H_ */
