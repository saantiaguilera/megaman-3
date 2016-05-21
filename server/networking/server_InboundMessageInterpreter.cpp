/*
 * server_iinboundMessageInterpreter.cpp
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#include "server_InboundMessageInterpreter.h"

#include <iostream>

#include "../../common/common_MessageProtocol.h"

InboundMessageInterpreter::InboundMessageInterpreter(int messageCode,
		unsigned int messageLength, const std::string& inboundMessage) {
	analizeMessageCode(messageCode);
}

void InboundMessageInterpreter::analizeMessageCode(int messageCode) {
	switch (messageCode) {
		case PLAYER_CONNECTED:
			std::cout << "Player connected!" << std::endl;
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

