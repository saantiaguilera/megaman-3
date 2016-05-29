/*
 * server_Bumpy.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Bumpy.h"

#include <Dynamics/b2Body.h>
#include <iostream>

#include "../../projectiles/server_Projectile.h"

#define ATTACK_INTERVAL_TICKS 3

Bumpy::Bumpy(float32 x, float32 y) : Mob(BUMPY_INITIAL_HP, x, y) {
	// Bumpy flies so...
	myBody->SetGravityScale(0);
}

Bumpy::~Bumpy() {
}

void Bumpy::receiveShotFromProjectile(Projectile* projectile) {
	decreaseHp(projectile->getDamage());
}

void Bumpy::update() {
	if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		// Shots downwards
		std::cout << "ATTACK!" << std::endl;
		ticksPassed = 0;
	}
	++ticksPassed;
}
