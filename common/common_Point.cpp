/*
 * common_Point.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "common_Point.h"

#include <sstream>

unsigned int Point::getX() const {
	return x;
}

void Point::setX(unsigned int x) {
	this->x = x;
}

unsigned int Point::getY() const {
	return y;
}

Point::Point() {
	y = 0;
	x = 0;
}

void Point::setY(unsigned int y) {
	this->y = y;
}

Point::~Point() {
}

std::string Point::toString() const {
	std::stringstream ss;
	ss << "(" << getX() << "," << getY() << ")";
	return ss.str();
}
