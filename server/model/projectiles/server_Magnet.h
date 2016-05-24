/*
 * server_Magnet.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_MAGNET_H_
#define SERVER_MODEL_PROJECTILES_SERVER_MAGNET_H_

#include "server_Projectile.h"

#define MAGNET_DAMAGE 4

class Magnet: public Projectile {
public:
	// Constructor
	Magnet();
	// Destroyer
	virtual ~Magnet();
private:
	// Copy constructor
	Magnet(const Magnet&);
	// Assignment operator
	Magnet& operator=(const Magnet&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_MAGNET_H_ */
