/*
 * server_Map.cpp
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#include "server_Map.h"

#include <iterator>

Map::Map(unsigned int sizeX, unsigned int sizeY) {
	tilesMatrix.resize(sizeX);
	for(unsigned i = 0; i < sizeX; ++i)
		tilesMatrix[i].resize(sizeY);

	for(unsigned i = 0; i < sizeX; i++) {
		for (unsigned j = 0; j < sizeY; j++) {
			tilesMatrix[i][j] = new Tile(i,j);
		}
	}
}

Map::~Map() {
	for(unsigned i = 0; i < tilesMatrix.size(); i++) {
		for (unsigned j = 0; j < tilesMatrix[i].size(); j++) {
			delete tilesMatrix[i][j];
		}
	}
}

