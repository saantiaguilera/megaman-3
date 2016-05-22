/*
 * server_Map.h
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_SERVER_MAP_H_
#define SERVER_MODEL_SERVER_MAP_H_

#include <vector>

#include "sever_Tile.h"

class Map {
private:
	std::vector< std::vector< Tile* > > tilesMatrix;
public:
	// Constructor, creates a map of sizeX*sizeY tiles
	Map(unsigned int sizeX, unsigned int sizeY);
	// Destroyer
	virtual ~Map();
	// Return the tile at x, y
	Tile* getTileAt(unsigned int x, unsigned int y);
private:
	// Copy constructor
	Map(const Map&);
	// Assignment operator
	Map& operator=(const Map&);
};

#endif /* SERVER_MODEL_SERVER_MAP_H_ */
