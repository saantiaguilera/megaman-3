/*
 * server_Projectile.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Projectile.h"

Projectile::~Projectile() {
}

Projectile::Projectile(unsigned int damage, projectile_types_t type) {
	PROJECTILE_TYPE = type;
	this->damage = damage;
}

int Projectile::getProjectileType() const {
	return PROJECTILE_TYPE;
}

unsigned int Projectile::getDamage() const {
	return damage;
}
