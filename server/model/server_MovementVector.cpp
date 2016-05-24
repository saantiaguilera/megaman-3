/*
 * server_movesVector.cpp
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#include "server_MovementVector.h"

#include <sstream>

MovementVector::MovementVector() : vx(0), vy(0), ax(0), ay(0){
}

std::string MovementVector::toString() const {
	std::stringstream ss;
	ss << "(" << getVx() << "," << getVy() << "," << getAx() << "," << getAy() << ")";
	return ss.str();
}

MovementVector::~MovementVector() {
}

float MovementVector::getAx() const {
	return ax;
}

void MovementVector::setAx(float ax) {
	this->ax = ax;
}

float MovementVector::getAy() const {
	return ay;
}

void MovementVector::setAy(float ay) {
	this->ay = ay;
}

float MovementVector::getVx() const {
	return vx;
}

void MovementVector::setVx(float vx) {
	this->vx = vx;
}

float MovementVector::getVy() const {
	return vy;
}

void MovementVector::setVy(float vy) {
	this->vy = vy;
}

void MovementVector::invertMovement() {
	vy *= -1;
	vx *= -1;
}
