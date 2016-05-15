/*
 * server_BossChamberGate.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_BOSSCHAMBERGATE_H_
#define SERVER_MODEL_OBSTACLES_SERVER_BOSSCHAMBERGATE_H_

#include "server_Obstacle.h"

#define BOSS_CHAMBER_GATE_IS_PASSABLE false

class BossChamberGate: public Obstacle {
public:
	// Constructor
	BossChamberGate();
	// Destroyer
	virtual ~BossChamberGate();
	// Applies effect on character
	virtual void haveEffectOn(Character* character);
private:
	// Copy constructor
	BossChamberGate(const BossChamberGate&);
	// Assignment operator
	BossChamberGate& operator=(const BossChamberGate&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_BOSSCHAMBERGATE_H_ */
