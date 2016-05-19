/*
 * server_Obstacle.cpp
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#include "server_Obstacle.h"

Obstacle::Obstacle(bool passable) : passable(passable) {}


bool Obstacle::isPassable() const {
	return passable;
}

Obstacle::~Obstacle() {
}

