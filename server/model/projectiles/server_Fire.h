/*
 * server_Fire.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_FIRE_H_
#define SERVER_MODEL_PROJECTILES_SERVER_FIRE_H_

#include "server_Projectile.h"

#define FIRE_DAMAGE 6


class Fire: public Projectile {
public:
	Fire() : Projectile(FIRE_DAMAGE, Projectile::FIRE) {}
	virtual ~Fire();
private:
	// Copy constructor
	Fire(const Fire&);
	// Assignment operator
	Fire& operator=(const Fire&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_FIRE_H_ */
