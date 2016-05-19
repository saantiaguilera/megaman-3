/*
 * server_Mob.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Mob.h"

Mob::Mob(unsigned int hp) : Character(hp), vulnerable(true) {}


bool Mob::isVulnerable() const {
	return vulnerable;
}

void Mob::setVulnerable(bool vulnerable) {
	this->vulnerable = vulnerable;
}

Mob::~Mob() {
}

