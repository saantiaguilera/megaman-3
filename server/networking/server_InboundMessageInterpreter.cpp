/*
 * server_iinboundMessageInterpreter.cpp
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#include "server_InboundMessageInterpreter.h"

#include <iostream>

#include "../../common/common_MessageProtocol.h"
#include "../game_engine/server_Engine.h"

InboundMessageInterpreter::InboundMessageInterpreter(int messageCode, const std::string& inboundMessage) {
	analizeMessageCode(messageCode, inboundMessage);
}

void InboundMessageInterpreter::analizeMessageCode(int messageCode, const std::string& inboundMessage) {
	switch (messageCode) {
		case PLAYER_CONNECTED:
			Engine::getInstance().addNewPlayer(inboundMessage);
			std::cout << Engine::getInstance().getPlayersList().back()->getName() <<" connected!" << std::endl;
			break;
		case START_GAME:
			std::cout << "Start game!" << std::endl;
			break;
		case KEY_PRESSED:
			std::cout << "Key Pressed!" << std::endl;
			break;
		case WEAPON_CHANGE:
			std::cout << "Weapon change!" << std::endl;
			break;
		default:
			break;
	}
}

InboundMessageInterpreter::~InboundMessageInterpreter() {
}

