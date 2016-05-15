/*
 * server_AmmoPack.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_AmmoPack.h"

AmmoPack::AmmoPack(float dropRate, unsigned int effectAmount) :
	Powerup(dropRate, effectAmount) {
}

AmmoPack::~AmmoPack() {
}

