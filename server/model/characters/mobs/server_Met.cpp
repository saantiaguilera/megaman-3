/*
 * server_Met.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Met.h"

Met::~Met() {
}

void Met::receiveShotFromWeapon(Bomb* bomb) {
	// It's supper efective
	hp -= bomb->getDamage() * 2;
}
