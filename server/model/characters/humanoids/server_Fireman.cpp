/*
 * server_Fireman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Fireman.h"

#include <iostream>

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../weapons/server_Flamethrower.h"

#define ATTACK_INTERVAL_TICKS 6

Fireman::Fireman(float32 x, float32 y) : Humanoid(FIREMAN_INITIAL_HP, x, y) {
	currentWeapon = new Flamethrower();
}

Fireman::~Fireman() {
}

void Fireman::update() {
	// Shots rings and moves, jumps high but not freq
	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		// Makes itself vulnerable and shots
		std::cout << "ATTACK!" << std::endl;
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

