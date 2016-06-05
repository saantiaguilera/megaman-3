/*
 * server_Fire.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Fire.h"

Fire::Fire(float32 x, float32 y) : Projectile(FIRE_DAMAGE, Projectile::FIRE, x, y) {}


Fire::~Fire() {
}

