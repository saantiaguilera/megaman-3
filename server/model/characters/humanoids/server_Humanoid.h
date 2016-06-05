/*
 * server_Humanoid.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_HUMANOID_H_
#define SERVER_MODEL_CHARACTERS_SERVER_HUMANOID_H_

#include <Common/b2Settings.h>

#include "../server_Character.h"

class Humanoid: public Character {
public:
	// Constructor
	Humanoid(unsigned int hp, float32 x, float32 y);
	// Destroyer
	virtual ~Humanoid();
	// Return object type
	virtual int getObjectType();
	// Handle collisions
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith);
	// Update object (AI)
	virtual void update() = 0;
private:
	// Copy constructor
	Humanoid(const Humanoid&);
	// Assignment operator
	Humanoid& operator=(const Humanoid&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_HUMANOID_H_ */
