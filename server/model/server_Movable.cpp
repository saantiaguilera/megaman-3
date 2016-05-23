/*
 * IMovable.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Movable.h"

Movable::~Movable() {
}

Movable::Movable() {
}

void Movable::move() {
	// TODO: Make use of accel
	position.setX(position.getX() + movementVector.getVx());
	position.setY(position.getY() + movementVector.getVy());
}
