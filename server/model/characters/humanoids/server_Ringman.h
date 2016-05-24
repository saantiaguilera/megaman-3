/*
 * server_Ringman.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_RINGMAN_H_
#define SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_RINGMAN_H_

#include "../../weapons/server_RingTosser.h"
#include "server_Humanoid.h"

#define RINGMAN_INITIAL_HP 100

class Ringman: public Humanoid {
public:
	// Constructor
	Ringman();
	// Destroyer
	virtual ~Ringman();
private:
	// Copy constructor
	Ringman(const Ringman&);
	// Assignment operator
	Ringman& operator=(const Ringman&);
};

#endif /* SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_RINGMAN_H_ */
