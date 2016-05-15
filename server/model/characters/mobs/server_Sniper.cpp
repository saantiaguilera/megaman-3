/*
 * server_Sniper.cpp
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#include "server_Sniper.h"

#include "../../projectiles/server_Projectile.h"

Sniper::Sniper() : Mob(SNIPER_INITAL_HP) {}


Sniper::~Sniper() {
}

void Sniper::receiveShotFromProjectile(Projectile* projectile) {
	int projectileType = projectile->getProjectileType();
	if (vulnerable){
		decreaseHp(projectile->getDamage());
	} else {
		if (projectileType == Projectile::FIRE || projectileType == Projectile::RING)
			decreaseHp(projectile->getDamage() / 2);
	}
}

