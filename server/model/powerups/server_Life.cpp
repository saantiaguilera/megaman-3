/*
 * server_Life.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_Life.h"

#include "../../game_engine/server_Player.h"
#include "../characters/humanoids/server_Megaman.h"

Life::Life(float32 x, float32 y) : Powerup(LIFE_DROP_RATE, LIFE_EFFECT_AMOUNT, x, y) {}

Life::~Life() {
}

void Life::haveEffectOn(Character* character) {
	((Megaman*)character)->getHumanOperator()->increasePlayerLives();
}
