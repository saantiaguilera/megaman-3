/*
 * server_Block.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_BLOCK_H_
#define SERVER_MODEL_OBSTACLES_SERVER_BLOCK_H_

#include "server_Obstacle.h"

class Block: public Obstacle {
public:
	// Constructor
	Block(float32 x, float32 y);
	// Destroyer
	virtual ~Block();
	// Applies effect on character
	virtual void haveEffectOn(Character* character);
private:
	// Copy constructor
	Block(const Block&);
	// Assignment operator
	Block& operator=(const Block&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_BLOCK_H_ */
