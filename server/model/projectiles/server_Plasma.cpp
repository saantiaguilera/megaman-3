/*
 * server_Plasma.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Plasma.h"

Plasma::Plasma(float32 x, float32 y, ORIENTATION facingPosition) : Projectile(PLASMA_DAMAGE, Projectile::PLASMA, x, y, facingPosition) {
}


Plasma::~Plasma() {
}

int Plasma::getTypeForSerialization() {
	return ObstacleViewTypePlasma;
}
