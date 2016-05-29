/*
 * server_AmmoPack.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_AmmoPack.h"

#include "../characters/server_Character.h"
#include "../weapons/server_Weapon.h"

AmmoPack::AmmoPack(unsigned int effectAmount, float32 x, float32 y) :
	Powerup(effectAmount, x, y) {
}

AmmoPack::~AmmoPack() {
}

void AmmoPack::haveEffectOn(Character* character) {
	character->getCurrentWeapon()->increaseAmmoBy(effectAmount);
}
