/*
 * server_Met.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Met.h"

#include <iostream>

#include "../../projectiles/server_Projectile.h"

#define TICKS_TO_HIDE_UNDER_HELMET 1
#define ATTACK_INTERVAL_TICKS 3

Met::Met(float32 x, float32 y) : Mob(MET_INITIAL_HP, x, y) {}

Met::~Met() {
}

void Met::receiveShotFromProjectile(Projectile* projectile) {
	int projectileType = projectile->getProjectileType();
	if (vulnerable){
		decreaseHp(projectile->getDamage());
	} else {
		if (projectileType == Projectile::BOMB || projectileType == Projectile::SPARK)
			decreaseHp(projectile->getDamage());
	}
}

void Met::update(){
	// Met does not move, just hides and attacks
	if (readyToAttack){
		// TODO: Gets vulnerable and shots in 3 different angles (left, up, right)
		vulnerable = true;
		std::cout << "ATTACK!" << std::endl;
		readyToAttack = false;
		ticksPassed = 0;
		return;
	}
	++ticksPassed;
	if (ticksPassed == TICKS_TO_HIDE_UNDER_HELMET){
		vulnerable = false;
	} else if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		readyToAttack = true;
	}
}
