/*
 * server_Magnet.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Magnet.h"

Magnet::Magnet(float32 x, float32 y) : Projectile(MAGNET_DAMAGE, Projectile::MAGNET, x, y) {}


Magnet::~Magnet() {
}

int Magnet::getTypeForSerialization() {
	return ObstacleViewTypeMagnet;
}

