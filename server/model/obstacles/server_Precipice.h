/*
 * server_Precipice.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_PRECIPICE_H_
#define SERVER_MODEL_OBSTACLES_SERVER_PRECIPICE_H_

#include "server_Obstacle.h"

#define PRECIPICE_IS_PASSABLE false

class Precipice: public Obstacle {
public:
	// Constructor
	Precipice();
	// Destroyer
	virtual ~Precipice();
	// Act on character
	// TODO
//	void haveEffectOn(Character* character);
private:
	// Copy constructor
	Precipice(const Precipice&);
	// Assignment operator
	Precipice& operator=(const Precipice&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_PRECIPICE_H_ */
