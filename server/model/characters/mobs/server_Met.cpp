/*
 * server_Met.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Met.h"

#include <iostream>
#include <string>

#include "../../projectiles/server_Projectile.h"

Met::Met() : Mob(MET_INITIAL_HP) {}

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
	if (readyToAttack){
		std::cout << "ATTACK!" << std::endl;
//		attack();
		readyToAttack = false;
		ticksPassed = 0;
		// Start moving to the other side
		movementVector.invertMovement();
		return;
	} else {
		move();
		std::cout << "Met's position: " << position.toString() << std::endl;
	}
	ticksPassed++;
	if (ticksPassed == 3)
		readyToAttack = true;
	if (ticksPassed == 2){
		movementVector.setVx(0);
		movementVector.setVy(1);
	}
	if (ticksPassed == 1){
		movementVector.setVx(1);
		movementVector.setVy(0);
	}
}
