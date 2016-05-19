/*
 * server_Plasma.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_PLASMA_H_
#define SERVER_MODEL_PROJECTILES_SERVER_PLASMA_H_

#include "server_Projectile.h"

#define PLASMA_DAMAGE 1

class Plasma: public Projectile {
public:
	// Constructor
	Plasma();
	// Destroyer
	virtual ~Plasma();
private:
	// Copy constructor
	Plasma(const Plasma&);
	// Assignment operator
	Plasma& operator=(const Plasma&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_PLASMA_H_ */
