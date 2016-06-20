/*
 * server_LootGenerator.cpp
 *
 *  Created on: May 28, 2016
 *      Author: mastanca
 */

#include "server_LootGenerator.h"

#include <cstdlib>
#include <iostream>

#include "../model/powerups/server_BigAmmoPack.h"
#include "../model/powerups/server_BigEnergyCapsule.h"
#include "../model/powerups/server_Life.h"
#include "../model/powerups/server_SmallAmmoPack.h"
#include "../model/powerups/server_SmallEnergyCapsule.h"
#include "server_Engine.h"

LootGenerator::LootGenerator() {

}

LootGenerator::~LootGenerator() {
}

void LootGenerator::generateLootAt(float32 x, float32 y) {
	// Generate a random number
	// If random number is equal or less than to the sum of all the drop rates
	// before the one chosen then generate a loot
	// TODO: Check leaks if they are not picked
	float randomNumber = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float probabilityRange = BIG_AMMO_PACK_DROP_RATE;
	if (randomNumber > NO_LOOT_DROP_RATE) {
		return;
	}
	if (randomNumber <= probabilityRange){
		// Create a big ammo pack
		notifyNewLootAt(new BigAmmoPack(x, y));
		return;
	}
	probabilityRange += BIG_ENERGY_CAPSULE_DROP_RATE;
	if (randomNumber <= probabilityRange) {
		// Create big energy capsule
		notifyNewLootAt(new BigEnergyCapsule(x, y));
		return;
	}
	probabilityRange += LIFE_DROP_RATE;
	if (randomNumber <= probabilityRange) {
		// Create life
		notifyNewLootAt(new Life(x, y));
		return;
	}
	probabilityRange += SMALL_AMMO_PACK_DROP_RATE;
	if (randomNumber <= probabilityRange) {
		notifyNewLootAt(new SmallAmmoPack(x, y));
		return;
	}
	probabilityRange += SMALL_ENERGY_CAPSULE_DROP_RATE;
	if (randomNumber <= probabilityRange) {
		notifyNewLootAt(new SmallEnergyCapsule(x, y));
		return;
	}
}

void LootGenerator::notifyNewLootAt(Powerup* powerup) {
	Engine::getInstance().markObjectForCreation(powerup);
}
