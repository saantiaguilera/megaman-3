/*
 * server_LootGenerator.cpp
 *
 *  Created on: May 28, 2016
 *      Author: mastanca
 */

#include "server_LootGenerator.h"

#include <cstdlib>

#include "../model/powerups/server_BigAmmoPack.h"
#include "../model/powerups/server_BigEnergyCapsule.h"
#include "../model/powerups/server_Life.h"
#include "../model/powerups/server_SmallAmmoPack.h"
#include "../model/powerups/server_SmallEnergyCapsule.h"

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
	if (probabilityRange > NO_LOOT_DROP_RATE) {
		return;
	} else if (randomNumber <= probabilityRange){
		// Create a big ammo pack
		new BigAmmoPack(x, y);
		probabilityRange += BIG_ENERGY_CAPSULE_DROP_RATE;
	} else if (randomNumber <= probabilityRange) {
		// Create big energy capsule
		new BigEnergyCapsule(x, y);
		probabilityRange += LIFE_DROP_RATE;
	} else if (randomNumber <= probabilityRange) {
		// Create life
		new Life(x, y);
		probabilityRange += SMALL_AMMO_PACK_DROP_RATE;
	} else if (randomNumber <= probabilityRange) {
		new SmallAmmoPack(x, y);
		probabilityRange += SMALL_ENERGY_CAPSULE_DROP_RATE;
	} else if (randomNumber <= probabilityRange) {
		new SmallEnergyCapsule(x, y);
	}
}
