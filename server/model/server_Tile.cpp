/*
 * server_Tile.cpp
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#include "sever_Tile.h"

Tile::Tile(unsigned int x, unsigned int y) {
	point.setX(x);
	point.setY(y);
}

Tile::~Tile() {
}

unsigned int Tile::getY() const {
	return point.getY();
}

unsigned int Tile::getX() const {
	return point.getX();
}
