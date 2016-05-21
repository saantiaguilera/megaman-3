/*
 * server_movesVector.cpp
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#include "server_MovementVector.h"

#include <sstream>

MovementVector::MovementVector() : x(0), y(0), velocity(1), acceleration(1){
}

float MovementVector::getAcceleration() const {
	return acceleration;
}

void MovementVector::setAcceleration(float acceleration) {
	this->acceleration = acceleration;
}

float MovementVector::getVelocity() const {
	return velocity;
}

void MovementVector::setVelocity(float velocity) {
	this->velocity = velocity;
}

unsigned int MovementVector::getX() const {
	return x;
}

void MovementVector::setX(unsigned int x) {
	this->x = x;
}

unsigned int MovementVector::getY() const {
	return y;
}

void MovementVector::setY(unsigned int y) {
	this->y = y;
}

std::string MovementVector::toString() const {
	std::stringstream ss;
	ss << "(" << getX() << "," << getY() << ")";
	return ss.str();
}

MovementVector::~MovementVector() {
}

