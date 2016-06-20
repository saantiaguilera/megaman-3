/*
 * server_Fireman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Fireman.h"

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../weapons/server_Flamethrower.h"


#include <iostream>

#define ATTACK_INTERVAL_TICKS 100

Fireman::Fireman(float32 x, float32 y) : Humanoid(FIREMAN_INITIAL_HP, x, y) {
	currentWeapon = new Flamethrower();
	notify();
}

Fireman::~Fireman() {
}

void Fireman::update() {
	// Shots rings and moves, jumps high but not freq
	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		attack();
		ticksPassed = 0;
		std::cout << "atack" << std::endl;

	} else if (ticksPassed == 3){
		move(MS_JUMP);
		std::cout << "Jump" << std::endl;
	} else if (ticksPassed == 5 || ticksPassed == 2){
		move(MS_RIGHT);
		std::cout << "Right" << std::endl;
	} else {
		move(MS_LEFT);
		std::cout << "Left" << std::endl;
	}

	std::cout << "atack" << std::endl;

	++ticksPassed;
}

int Fireman::getTypeForSerialization() {
	return ObstacleViewTypeFireman;
}
