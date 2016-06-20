/*
 * server_Powerup.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_POWERUP_H_
#define SERVER_MODEL_POWERUPS_SERVER_POWERUP_H_

#include <Common/b2Settings.h>

#include "../../game_engine/physics/server_PhysicObject.h"
#include "../characters/server_Character.h"

class Powerup : public PhysicObject {
protected:
	// Amount of its effect to be applied
	unsigned int effectAmount;
	// Initial locations
	float32 initialX, initialY;
	// Return object type
	virtual int getObjectType();
public:
	// Constructor
	Powerup(unsigned int effectAmount, float32 x, float32 y);
	// Destroyer
	virtual ~Powerup();
	// Overrided by children, applies effect on parameter
	virtual void haveEffectOn(Character* character) = 0;
	// Get type for serialization
	virtual int getTypeForSerialization() = 0;
	// Set body for runtime creation
	void setBody();
	virtual float32 getWidth();
	virtual float32 getHeight();
private:
	// Copy constructor
	Powerup(const Powerup&);
	// Assignment operator
	Powerup& operator=(const Powerup&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_POWERUP_H_ */
