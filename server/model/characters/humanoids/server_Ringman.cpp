/*
 * sever_Ringman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Ringman.h"

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../weapons/server_RingTosser.h"

#define ATTACK_INTERVAL_TICKS 5

Ringman::Ringman(float32 x, float32 y) : Humanoid(RINGMAN_INITIAL_HP, x, y) {
	currentWeapon = new RingTosser();
}

Ringman::~Ringman() {
}

void Ringman::update() {
	// Shots rings and moves, jumps high but not freq
	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		attack();
		ticksPassed = 0;
	} else if (ticksPassed == 3){
		move(MS_JUMP);
	} else if (ticksPassed == 5 || ticksPassed == 2){
		move(MS_RIGHT);
	} else {
		move(MS_LEFT);
	}
	++ticksPassed;
}

int Ringman::getTypeForSerialization() {
	return ObstacleViewTypeRingman;
}

