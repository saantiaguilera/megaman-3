/*
 * server_iinboundMessageInterpreter.cpp
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#include "server_InboundMessagesController.h"

#include <iostream>
#include <sstream>
#include <list>

#include "../../common/common_MessageProtocol.h"
#include "../game_engine/server_Engine.h"
#include "../game_engine/server_Player.h"
#include "../serializers/server_NewPlayerSerializer.h"
#include "../serializers/server_StartGameSerializer.h"

#define MAX_PLAYERS_COUNT 4

InboundMessagesController::InboundMessagesController(int messageCode, const std::string& inboundMessage) {
	analizeMessageCode(messageCode, inboundMessage);
}

void InboundMessagesController::analizeMessageCode(int messageCode, const std::string& inboundMessage) {
	std::list<Player*> playerList = Engine::getInstance().getPlayersList();
	Player* desiredPlayer;
	switch (messageCode) {
		case PLAYER_CONNECTED:
			if (Engine::getInstance().getPlayersList().size() < MAX_PLAYERS_COUNT){
				Engine::getInstance().addNewPlayer(inboundMessage);
				std::cout << Engine::getInstance().getPlayersList().back()->getName() <<" connected!" << std::endl;
				NewPlayerSerializer newPlayerSerializer(inboundMessage);
			}
			break;
		case START_GAME:
			if (Engine::getInstance().getPlayersList().size() < MAX_PLAYERS_COUNT){
				std::cout << "Start game!" << std::endl;
				// Set the flag of th engine to ready to start
				// TODO: Should check that the player willing to start is the admin
				Engine::getInstance().setReadyToStart(true);
				StartGameSerializer startGameSerializer;
			}
			break;
		case KEY_PRESSED:
			std::cout << "Key Pressed!" << std::endl;
			// According to the pressed key we should do something
			// We should get the player id, the key pressed
			 desiredPlayer = getDesiredPlayer(inboundMessage);
			// TODO: Here move the megaman of the player
			break;
		case WEAPON_CHANGE:
			std::cout << "Weapon change!" << std::endl;
			// Weapons should have an id, this should have an the id of the player
			// and the corresponding weapon id to switch
			desiredPlayer = getDesiredPlayer(inboundMessage);
			break;
		default:
			break;
	}
}

Player* InboundMessagesController::getDesiredPlayer(
		const std::string& playerId) {
	std::list<Player*> playerList = Engine::getInstance().getPlayersList();
	std::stringstream ss(playerId);
	unsigned int incomingId;
	ss >> incomingId;
	for (std::list<Player*>::iterator it = playerList.begin();
			it != playerList.end(); ++it) {
		if ((*it)->getId() == incomingId)
			return *it;
	}
	return NULL;
}

InboundMessagesController::~InboundMessagesController() {
}

