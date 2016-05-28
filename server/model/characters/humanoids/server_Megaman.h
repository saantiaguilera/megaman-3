/*
 * server_Megaman.h
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_MEGAMAN_H_
#define SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_MEGAMAN_H_

#include <Common/b2Settings.h>

#include "server_Humanoid.h"

#define MEGAMAN_INITIAL_HP 150

class Megaman : public Humanoid {
public:
	// Constructor
	Megaman(float32 x, float32 y);
	// Destroyer
	virtual ~Megaman();
	// Return object type
	virtual int getObjectType();
	// Handle collisions
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith);
	// Update object (AI)
	// TODO: For testing collisions
	virtual void update();
private:
	// Copy constructor
	Megaman(const Megaman&);
	// Assignment operator
	Megaman& operator=(const Megaman&);
};

#endif /* SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_MEGAMAN_H_ */
