/*
 * sever_Ringman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Ringman.h"

#include <vector>

#include "../../../../common/common_MapConstants.h"
#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../../game_engine/server_Engine.h"
#include "../../weapons/server_RingTosser.h"

#define ATTACK_INTERVAL_TICKS 100

Ringman::Ringman(float32 x, float32 y) : Humanoid(RINGMAN_INITIAL_HP, x, y) {
	currentWeapon = new RingTosser();
	notify();

	Engine::getInstance().getUpdatablesList()->push_back(this);
	setUpdatable(true);
}

Ringman::~Ringman() {
	Megaman* megaman;
	for (Player* player : Engine::getInstance().getPlayersList()){
		megaman = player->getMegaman();
		if (megaman != NULL){
			megaman->makeWeaponAvailable(RING_TOSSER, new RingTosser());
		}
	}
	bossDestroyed();
}

void Ringman::update() {
	// Shots rings and moves, jumps high but not freq
//	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
//		attack();
//		ticksPassed = 0;
//	} else if (ticksPassed == 30){
//		move(MS_JUMP);
//	} else if (ticksPassed == 50 || ticksPassed == 20){
//		move(MS_RIGHT);
//	} else {
//		move(MS_LEFT);
//	}
//	++ticksPassed;

	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		ticksPassed = 0;
	} else

	if (ticksPassed == 40){
		move(MS_JUMP);
	} else
	if (ticksPassed == 41) {
		move(MS_STOP);

		setUpdatable(true);
	}

	if (ticksPassed > 41 && ticksPassed <= 60){
		move(MS_RIGHT);
	} else
	if (ticksPassed == 61) {
		move(MS_STOP);

		setUpdatable(true);
	} else

	if (ticksPassed > 61 && ticksPassed < 80) {
		move(MS_LEFT);
	} else
	if (ticksPassed == 99) {
		move(MS_STOP);

		setUpdatable(true);
	}

	bool willAttck = ticksPassed % 30 == 0;

	if (willAttck) {
		attack();
	}

	++ticksPassed;
}

int Ringman::getTypeForSerialization() {
	return ObstacleViewTypeRingman;
}
