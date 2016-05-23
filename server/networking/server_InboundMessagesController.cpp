/*
 * server_iinboundMessageInterpreter.cpp
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#include "server_InboundMessagesController.h"

#include <iostream>

#include "../../common/common_MessageProtocol.h"
#include "../game_engine/server_Engine.h"

#define MAX_PLAYERS_COUNT 4

InboundMessagesController::InboundMessagesController(int messageCode, const std::string& inboundMessage) {
	analizeMessageCode(messageCode, inboundMessage);
}

void InboundMessagesController::analizeMessageCode(int messageCode, const std::string& inboundMessage) {
	switch (messageCode) {
		case PLAYER_CONNECTED:
			if (Engine::getInstance().getPlayersList().size() < MAX_PLAYERS_COUNT){
				Engine::getInstance().addNewPlayer(inboundMessage);
				std::cout << Engine::getInstance().getPlayersList().back()->getName() <<" connected!" << std::endl;
			}
			break;
		case START_GAME:
			std::cout << "Start game!" << std::endl;
			// Make the engine run
			// TODO: Should check that the player willing to start is the admin
			// TODO: Should validate the amount of players to be at least 1
			Engine::getInstance().start();
			break;
		case KEY_PRESSED:
			std::cout << "Key Pressed!" << std::endl;
			// According to the pressed key we should do something
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

