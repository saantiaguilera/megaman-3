/*
 * server_Sparkman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Sparkman.h"

#include <vector>

#include "../../../../common/common_MapConstants.h"
#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../../game_engine/server_Engine.h"
#include "../../weapons/server_SparksCannon.h"

#define ATTACK_INTERVAL_TICKS 100


Sparkman::Sparkman(float32 x, float32 y) : Humanoid(SPARKMAN_INITIAL_HP, x, y) {
	currentWeapon = new SparksCannon();
	notify();

	Engine::getInstance().getUpdatablesList()->push_back(this);
	setUpdatable(true);
}

Sparkman::~Sparkman() {
	for (Player* player : Engine::getInstance().getPlayersList()){
		player->getMegaman()->makeWeaponAvailable(SPARKS_CANNON, new SparksCannon());
	}
}

void Sparkman::update() {
	// Shots sparks, jumps all the time. Shots straight and oblique
	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		attack();
		ticksPassed = 0;
	}else {
		move(MS_JUMP);
	}
	++ticksPassed;
}

int Sparkman::getTypeForSerialization() {
	return ObstacleViewTypeSparkman;
}

