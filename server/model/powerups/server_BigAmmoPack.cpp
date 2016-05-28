/*
 * server_BigAmmoPack.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_BigAmmoPack.h"

BigAmmoPack::BigAmmoPack(float32 x, float32 y) :
		AmmoPack(BIG_AMMO_PACK_DROP_RATE,
		BIG_AMMO_PACK_EFFECT_AMMOUNT, x, y) {
}

BigAmmoPack::~BigAmmoPack() {
}

