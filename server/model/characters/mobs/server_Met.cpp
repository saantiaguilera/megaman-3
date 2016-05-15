/*
 * server_Met.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Met.h"

#include "../../projectiles/server_Projectile.h"

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
