/*
 * server_NormalSniper.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_NormalSniper.h"

#include <iostream>

#define ATTACK_INTERVAL_TICKS 3

NormalSniper::NormalSniper(float32 x, float32 y) : Sniper(x, y) {
}

NormalSniper::~NormalSniper() {
}

void NormalSniper::update() {
	// Apparently he doesn't move
	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		// Makes itself vulnerable and shots
		vulnerable = true;
		std::cout << "ATTACK!" << std::endl;
		ticksPassed = 0;
	}
	++ticksPassed;
	if (ticksPassed == 1) {
		vulnerable = false;
	}
}

