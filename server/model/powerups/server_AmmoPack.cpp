/*
 * server_AmmoPack.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_AmmoPack.h"

#include "../../game_engine/server_Engine.h"
#include "../../game_engine/server_EventContext.h"
#include "../../serializers/server_AmmoChangeSerializer.h"
#include "../characters/server_Character.h"
#include "../characters/humanoids/server_Megaman.h"
#include "../weapons/server_Weapon.h"

AmmoPack::AmmoPack(unsigned int effectAmount, float32 x, float32 y) :
	Powerup(effectAmount, x, y) {
}

AmmoPack::~AmmoPack() {
}

void AmmoPack::haveEffectOn(Character* character) {
	character->getCurrentWeapon()->increaseAmmoBy(effectAmount);
	AmmoChangeSerializer* ammoChangeSerializer = new AmmoChangeSerializer(character->getCurrentWeapon());

	if (!character->isAI())
		ammoChangeSerializer->setDispatchClient(dynamic_cast<Megaman*>(character)->getBoundId());

	Engine::getInstance().getContext()->dispatchEvent(ammoChangeSerializer);
}
