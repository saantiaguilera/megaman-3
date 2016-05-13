/*
 * server_Humanoid.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_HUMANOID_H_
#define SERVER_MODEL_CHARACTERS_SERVER_HUMANOID_H_

#include "server_Character.h"

class Humanoid: public Character {
public:
	// Constructor
	Humanoid(unsigned int hp) : Character(hp) {}
	// Destroyer
	virtual ~Humanoid();
private:
	// Copy constructor
	Humanoid(const Humanoid&);
	// Assignment operator
	Humanoid& operator=(const Humanoid&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_HUMANOID_H_ */
