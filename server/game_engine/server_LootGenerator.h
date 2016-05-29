/*
 * server_LootGenerator.h
 *
 *  Created on: May 28, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_LOOTGENERATOR_H_
#define SERVER_GAME_ENGINE_SERVER_LOOTGENERATOR_H_

#define BIG_AMMO_PACK_DROP_RATE 0.05
#define BIG_ENERGY_CAPSULE_DROP_RATE 0.05
#define LIFE_DROP_RATE 0.01
#define SMALL_AMMO_PACK_DROP_RATE 0.1
#define SMALL_ENERGY_CAPSULE_DROP_RATE 0.1

class LootGenerator {
public:
	// Constructor
	LootGenerator();
	// Destroyer
	virtual ~LootGenerator();
	// Generate loot according to drop rates
	void generateLoot();
private:
	// Copy constructor
	LootGenerator(const LootGenerator&);
	// Assignment operator
	LootGenerator& operator=(const LootGenerator&);
};

#endif /* SERVER_GAME_ENGINE_SERVER_LOOTGENERATOR_H_ */
