/*
 * server_Powerup.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_POWERUPS_SERVER_POWERUP_H_
#define SERVER_MODEL_POWERUPS_SERVER_POWERUP_H_

#include "../../../common/common_Point.h"
#include "../../game_engine/physics/server_PhysicObject.h"

class Powerup : public PhysicObject {
protected:
	// my current position
	Point myPoint;
	// Powerups drop rate
	float dropRate;
	// Amount of its effect to be applied
	unsigned int effectAmount;
	// Overrided by children, applies effect on parameter
	virtual void haveEffectOn() = 0;
	// Return object type
	virtual int getObjectType();
public:
	// Constructor
	Powerup(float dropRate, unsigned int effectAmount);
	// Destroyer
	virtual ~Powerup();
private:
	// Copy constructor
	Powerup(const Powerup&);
	// Assignment operator
	Powerup& operator=(const Powerup&);
};

#endif /* SERVER_MODEL_POWERUPS_SERVER_POWERUP_H_ */
