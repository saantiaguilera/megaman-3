/*
 * sever_Tile.h
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_SEVER_TILE_H_
#define SERVER_MODEL_SEVER_TILE_H_

#include "../../common/common_Point.h"

class Tile {
private:
	Point point;
public:
	// Constructor
	Tile(unsigned int x, unsigned int y);
	// Destroyer
	virtual ~Tile();
	// Return my y position
	unsigned int getY() const;
	// Return my x position
	unsigned int getX() const;
private:
	// Copy constructor
	Tile(const Tile&);
	// Assignment operator
	Tile& operator=(const Tile&);
};

#endif /* SERVER_MODEL_SEVER_TILE_H_ */
