/*
 * server_Sparkman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Sparkman.h"

#include "../../weapons/server_SparksCannon.h"

Sparkman::Sparkman(float32 x, float32 y) : Humanoid(SPARKMAN_INITIAL_HP, x, y) {
	currentWeapon = new SparksCannon();
}

Sparkman::~Sparkman() {
}

