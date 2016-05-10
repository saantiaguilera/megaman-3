/*
 * server_Powerup.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_SERVER_POWERUP_H_
#define SERVER_MODEL_SERVER_POWERUP_H_

class Powerup {
protected:
	// Powerups drop rate
	float dropRate;
	// Amount of its effect to be applied
	unsigned int effectAmount;
	// Overrided by children, applies effect on parameter
	virtual void haveEffectOn() = 0;
public:
	// Constructor
	Powerup(float dropRate, unsigned int effectAmount) :
			dropRate(dropRate), effectAmount(effectAmount) {
	}
	// Destroyer
	virtual ~Powerup();
private:
	// Copy constructor
	Powerup(const Powerup&);
	// Assignment operator
	Powerup& operator=(const Powerup&);
};

#endif /* SERVER_MODEL_SERVER_POWERUP_H_ */
