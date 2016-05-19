/*
 * IMovable.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "IMovable.h"

IMovable::~IMovable() {
}

void IMovable::moveRight() {
	myPoint.setX(myPoint.getX() + 1);
}

void IMovable::moveUp() {
	myPoint.setY(myPoint.getY() + 1);
}

void IMovable::moveLeft() {
	myPoint.setX(myPoint.getX() - 1);
}

const Point& IMovable::getMyPoint() const {
	return myPoint;
}

void IMovable::moveDown() {
	myPoint.setY(myPoint.getY() - 1);
}
