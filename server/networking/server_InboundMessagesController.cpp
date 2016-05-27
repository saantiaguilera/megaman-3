/*
 * server_iinboundMessageInterpreter.cpp
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#include "server_InboundMessagesController.h"

#include <algorithm>
#include <iostream>
#include <list>

#include "../../common/common_MessageProtocol.h"
#include "../functors/server_FindByPlayerId.h"
#include "../game_engine/server_Engine.h"
#include "../game_engine/server_Player.h"

#define MAX_PLAYERS_COUNT 4

InboundMessagesController::InboundMessagesController(int messageCode, const std::string& inboundMessage) {
	analizeMessageCode(messageCode, inboundMessage);
}

void InboundMessagesController::analizeMessageCode(int messageCode, const std::string& inboundMessage) {
	unsigned int incomingId;
	std::list<Player*>::iterator it;
	switch (messageCode) {
		case PLAYER_CONNECTED:
			if (Engine::getInstance().getPlayersList().size() < MAX_PLAYERS_COUNT){
				Engine::getInstance().addNewPlayer(inboundMessage);
				std::cout << Engine::getInstance().getPlayersList().back()->getName() <<" connected!" << std::endl;
			}
			break;
		case START_GAME:
			std::cout << "Start game!" << std::endl;
			// Set the flag of th engine to ready to start
			// TODO: Should check that the player willing to start is the admin
			// TODO: Should validate the amount of players to be at least 1
			Engine::getInstance().setReadyToStart(true);
			break;
		case KEY_PRESSED:
			std::cout << "Key Pressed!" << std::endl;
			// According to the pressed key we should do something
			// We should get the player id, the key pressed
			incomingId = 1; // TODO: Replace with inbound one
			it = std::find_if(Engine::getInstance().getPlayersList().begin(), Engine::getInstance().getPlayersList().end(), FindByPlayerId(incomingId));
			break;
		case WEAPON_CHANGE:
			std::cout << "Weapon change!" << std::endl;
			// Weapons should have an id, this should have an the id of the player
			// and the corresponding weapon id to switch
			break;
		default:
			break;
	}
}

InboundMessagesController::~InboundMessagesController() {
}

