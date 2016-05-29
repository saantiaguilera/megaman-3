/*
 * server_LootGenerator.cpp
 *
 *  Created on: May 28, 2016
 *      Author: mastanca
 */

#include "server_LootGenerator.h"

#include <cstdlib>

LootGenerator::LootGenerator() {

}

LootGenerator::~LootGenerator() {
}

void LootGenerator::generateLoot() {
	// Generate a random number
	// If random number is equal or less than to the sum of all the drop rates
	// before the one chosen then generate a loot
	float randomNumber = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);


}
