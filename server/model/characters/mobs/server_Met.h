/*
 * server_Met.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_MOBS_SERVER_MET_H_
#define SERVER_MODEL_CHARACTERS_MOBS_SERVER_MET_H_

#include "server_Mob.h"

#define MET_INITIAL_HP 1

class Met: public Mob {
public:
	// Constructor
	Met();
	// Destroyer
	virtual ~Met();
	// Receive shot from weapon
	void receiveShotFromProjectile(Projectile* projectile);

	void update();
private:
	// Copy constructor
	Met(const Met&);
	// Assignment operator
	Met& operator=(const Met&);
};

#endif /* SERVER_MODEL_CHARACTERS_MOBS_SERVER_MET_H_ */
