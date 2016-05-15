/*
 * server_Sparkman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Sparkman.h"

Sparkman::Sparkman() : Humanoid(SPARKMAN_INITIAL_HP) {
	currentWeapon = new SparksCannon();
}

Sparkman::~Sparkman() {
}

