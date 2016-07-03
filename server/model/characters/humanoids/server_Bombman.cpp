/*
 * server_Bombman.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Bombman.h"

#include <vector>

#include "../../../../common/common_MapConstants.h"
#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../../game_engine/server_Engine.h"
#include "../../../game_engine/server_EventContext.h"
#include "../../../game_engine/server_Player.h"
#include "../../../serializers/server_EndGameSerializer.h"
#include "../../weapons/server_BombCannon.h"
#include "../../weapons/server_Weapon.h"
#include "server_Megaman.h"

#define ATTACK_INTERVAL_TICKS 100

Bombman::Bombman(float32 x, float32 y) : Humanoid(BOMBMAN_INITIAL_HP, x, y) {
	currentWeapon = new BombCannon();
	notify();

	Engine::getInstance().getUpdatablesList()->push_back(this);
	setUpdatable(true);
}

Bombman::~Bombman() {
	Megaman* megaman;
	for (Player* player : Engine::getInstance().getPlayersList()){
		megaman = player->getMegaman();
		if (megaman != NULL){
			megaman->makeWeaponAvailable(BOMB_CANNON, new BombCannon());
		}
	}
	bossDestroyed();
}

void Bombman::update() {
	// Shots bombs, jumps and walks

		if (ticksPassed == ATTACK_INTERVAL_TICKS) {
			ticksPassed = 0;
			move(MS_LEFT);
		} else

		if (ticksPassed == 10){
			move(MS_STOP);
			setUpdatable(true);

			attack();
		} else
		if (ticksPassed == 20) {
			attack();
		} else if (ticksPassed == 30) {
			attack();
		}

		if (ticksPassed == 40){
			move(MS_JUMP);
		} else
		if (ticksPassed == 50) {
			move(MS_RIGHT);
		} else

		if (ticksPassed == 60) {
			move(MS_STOP);
			setUpdatable(true);

			attack();
		} else
		if (ticksPassed == 70) {
			attack();
		} else
		if (ticksPassed == 80) {
			move(MS_LEFT);

			attack();
		} else
		if (ticksPassed == 90) {
			move(MS_STOP);
			setUpdatable(true);
		}

		++ticksPassed;
}

int Bombman::getTypeForSerialization() {
	return ObstacleViewTypeBombman;
}
