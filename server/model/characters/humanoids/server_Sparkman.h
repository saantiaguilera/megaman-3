/*
 * server_Sparkman.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_SPARKMAN_H_
#define SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_SPARKMAN_H_

#include "../../weapons/server_SparksCannon.h"
#include "server_Humanoid.h"

#define SPARKMAN_INITIAL_HP 90

class Sparkman: public Humanoid {
public:
	// Constructor
	Sparkman();
	// Destroyer
	virtual ~Sparkman();
private:
	// Copy constructor
	Sparkman(const Sparkman&);
	// Assignment operator
	Sparkman& operator=(const Sparkman&);
};

#endif /* SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_SPARKMAN_H_ */
