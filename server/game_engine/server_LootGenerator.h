/*
 * server_LootGenerator.h
 *
 *  Created on: May 28, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_LOOTGENERATOR_H_
#define SERVER_GAME_ENGINE_SERVER_LOOTGENERATOR_H_

#include <Common/b2Settings.h>
#include "../model/powerups/server_Powerup.h"

#define BIG_AMMO_PACK_DROP_RATE 0.05
#define BIG_ENERGY_CAPSULE_DROP_RATE 0.05
#define LIFE_DROP_RATE 0.01
#define SMALL_AMMO_PACK_DROP_RATE 0.1
#define SMALL_ENERGY_CAPSULE_DROP_RATE 0.1
#define NO_LOOT_DROP_RATE  1 - (BIG_AMMO_PACK_DROP_RATE + \
		BIG_ENERGY_CAPSULE_DROP_RATE + LIFE_DROP_RATE + \
		SMALL_AMMO_PACK_DROP_RATE + SMALL_ENERGY_CAPSULE_DROP_RATE)

class LootGenerator {
public:
	// Constructor
	LootGenerator();
	// Destroyer
	virtual ~LootGenerator();
	// Generate loot according to drop rates at position x y
	void generateLootAt(float32 x, float32 y);
	// Push dropped event
	void notifyNewLootAt(Powerup* powerup);
private:
	// Copy constructor
	LootGenerator(const LootGenerator&);
	// Assignment operator
	LootGenerator& operator=(const LootGenerator&);
};

#endif /* SERVER_GAME_ENGINE_SERVER_LOOTGENERATOR_H_ */
