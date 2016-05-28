/*
 * server_AmmoPack.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_AmmoPack.h"

AmmoPack::AmmoPack(float dropRate, unsigned int effectAmount, float32 x, float32 y) :
	Powerup(dropRate, effectAmount, x, y) {
}

AmmoPack::~AmmoPack() {
}

