/*
 * server_Fireman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Fireman.h"

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../weapons/server_Flamethrower.h"
#include "../../../game_engine/server_Engine.h"

#include <iostream>

#define ATTACK_INTERVAL_TICKS 100

Fireman::Fireman(float32 x, float32 y) : Humanoid(FIREMAN_INITIAL_HP, x, y) {
	currentWeapon = new Flamethrower();
	notify();

	Engine::getInstance().getUpdatablesList()->push_back(this);
	setUpdatable(true);
}

Fireman::~Fireman() {
	for (Player* player : Engine::getInstance().getPlayersList()){
		player->getMegaman()->makeWeaponAvailable(FLAMETHROWER, new Flamethrower());
	}
	bossDestroyed();
}

void Fireman::update() {
	// Shots rings and moves, jumps high but not freq

	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		ticksPassed = 0;
		move(MS_LEFT);
	} else if (ticksPassed == 10){
		move(MS_STOP);
		setUpdatable(true);

		attack();
	} else if (ticksPassed == 20) {
		attack();
	} else if (ticksPassed == 30) {
		attack();
	}

	if (ticksPassed == 40){
		move(MS_JUMP);
	} else if (ticksPassed == 50) {
		move(MS_RIGHT);
	} else if (ticksPassed == 60) {
		move(MS_STOP);
		setUpdatable(true);

		attack();
	} else if (ticksPassed == 70) {
		attack();
	} else if (ticksPassed == 80) {
		move(MS_LEFT);

		attack();
	} else if (ticksPassed == 90) {
		move(MS_STOP);
		setUpdatable(true);
	}

	++ticksPassed;
}

int Fireman::getTypeForSerialization() {
	return ObstacleViewTypeFireman;
}
