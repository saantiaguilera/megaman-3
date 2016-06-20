/*
 * server_Flamethrower.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_Flamethrower.h"

#include <iostream>

#include "../../game_engine/server_Engine.h"
#include "../projectiles/server_Fire.h"

Flamethrower::Flamethrower() : Weapon(FLAMETHROWER_MAX_AMMO) {}


Flamethrower::~Flamethrower() {
}

void Flamethrower::fire(float32 x, float32 y, PhysicObject::ORIENTATION facingPosition) {
	std::cout << "Firing flamethrower" << std::endl;
	if (ammo > 0){
		--ammo;
		Engine::getInstance().markObjectForCreation(new Fire(x, y, facingPosition));
	}
}

unsigned int Flamethrower::getMaxAmmo() {
	return FLAMETHROWER_MAX_AMMO;
}
