/*
 * server_MagnetMan.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Magnetman.h"

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../weapons/server_MagnetCannon.h"

#define ATTACK_INTERVAL_TICKS 6

MagnetMan::MagnetMan(float32 x, float32 y) : Humanoid(MAGNETMAN_INITIAL_HP, x, y) {
	currentWeapon = new MagnetCannon();
}

MagnetMan::~MagnetMan() {
}

void MagnetMan::update() {
	// Shots magnets, jumps little and walks (directed shots???)
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

int MagnetMan::getTypeForSerialization() {
	return ObstacleViewTypeMagnetman;
}
