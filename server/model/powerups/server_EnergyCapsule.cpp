/*
 * server_EnergyCapsule.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_EnergyCapsule.h"

#include "../../game_engine/server_Engine.h"
#include "../../game_engine/server_EventContext.h"
#include "../../serializers/server_HpChangeSerializer.h"
#include "../characters/server_Character.h"

EnergyCapsule::EnergyCapsule(unsigned int effectAmount, float32 x, float32 y) :
		Powerup(effectAmount, x, y) {
}

EnergyCapsule::~EnergyCapsule() {
}

void EnergyCapsule::haveEffectOn(Character* character) {
	character->increaseHP(effectAmount);
	HpChangeSerializer* hpChangeSerializer = new HpChangeSerializer(character->getHp(), character);
	Engine::getInstance().getContext()->dispatchEvent(hpChangeSerializer);
}
