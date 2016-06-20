/*
 * server_Life.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_Life.h"

#include "../../game_engine/server_Engine.h"
#include "../../game_engine/server_EventContext.h"
#include "../../game_engine/server_Player.h"
#include "../../serializers/server_LifeChangeSerializer.h"
#include "../characters/humanoids/server_Megaman.h"

Life::Life(float32 x, float32 y) : Powerup(LIFE_EFFECT_AMOUNT, x, y) {
}

Life::~Life() {
}

void Life::haveEffectOn(Character* character) {
	((Megaman*)character)->getHumanOperator()->increasePlayerLives();
	LifeChangeSerializer* lifeChangeSerializer = new LifeChangeSerializer(dynamic_cast<Megaman*>(character)->getHumanOperator()->getLives());

	if (!character->isAI())
		lifeChangeSerializer->setDispatchClient(dynamic_cast<Megaman*>(character)->getBoundId());

	Engine::getInstance().getContext()->dispatchEvent(lifeChangeSerializer);
}

int Life::getTypeForSerialization() {
	return ObstacleViewTypeLife;
}
