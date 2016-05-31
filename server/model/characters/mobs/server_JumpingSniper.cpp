/*
 * server_JumpingSniper.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_JumpingSniper.h"

#include <iostream>

#define ATTACK_INTERVAL_TICKS 3

JumpingSniper::JumpingSniper(float32 x, float32 y) : Sniper(x, y) {
}

JumpingSniper::~JumpingSniper() {
}

void JumpingSniper::update() {
	// Jumps between shots
	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		// Makes itself vulnerable and shots
		vulnerable = true;
		attack();
		ticksPassed = 0;
	} else {
		vulnerable = false;
		move(MS_JUMP);
	}
	++ticksPassed;
}

