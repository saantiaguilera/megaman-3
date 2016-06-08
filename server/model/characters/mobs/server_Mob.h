/*
 * server_Mob.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_MOBS_SERVER_MOB_H_
#define SERVER_MODEL_CHARACTERS_MOBS_SERVER_MOB_H_

#include <Common/b2Settings.h>

#include "../server_Character.h"

class Mob: public Character {
protected:
	// Is affected by attacks?
	bool vulnerable;
public:
	// Constructor
	Mob(unsigned int hp, float32 x, float32 y);
	// Destroyer
	virtual ~Mob();
	// Is currently vulnerable?
	bool isVulnerable() const;
	// Sets vulnerability (true/false)
	void setVulnerable(bool vulnerable);
	virtual void update() {}
	// Return object type
	virtual int getObjectType();
	// Handle collision
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith);
	// Get type for serialization
	virtual int getTypeForSerialization() = 0;

private:
	// Copy constructor
	Mob(const Mob&);
	// Assignment operator
	Mob& operator=(const Mob&);
};

#endif /* SERVER_MODEL_CHARACTERS_MOBS_SERVER_MOB_H_ */
