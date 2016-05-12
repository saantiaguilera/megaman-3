/*
 * server_Block.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_BLOCK_H_
#define SERVER_MODEL_OBSTACLES_SERVER_BLOCK_H_

#include "server_Obstacle.h"

#define BLOCK_IS_PASSABLE false

class Block: public Obstacle {
public:
	// Constructor
	Block() : Obstacle(BLOCK_IS_PASSABLE) {}
	// Destroyer
	virtual ~Block();
private:
	// Copy constructor
	Block(const Block&);
	// Assignment operator
	Block& operator=(const Block&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_BLOCK_H_ */
