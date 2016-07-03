/*
 * server_Met.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Met.h"

#include <iostream>

#include "../../projectiles/server_Projectile.h"

Met::Met(float32 x, float32 y) : Mob(MET_INITIAL_HP, x, y) {
	facingPosition = OR_LEFT;
	notify();
}

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

	notifyMovement();
}

void Met::update(){
	// Met does not move, just hides and attacks
	if (readyToAttack){
		// TODO: Gets vulnerable and shots in 3 different angles (left, up, right)
		vulnerable = true;
		attack();
		readyToAttack = false;
		ticksPassed = 0;
		return;
	}
	++ticksPassed;
	if (ticksPassed == ATTACK_INTERVAL_TICKS / 2){
		vulnerable = false;
	} else if (ticksPassed == ATTACK_INTERVAL_TICKS) {
		readyToAttack = true;
	}
}

int Met::getTypeForSerialization() {
	return ObstacleViewTypeMet;
}
