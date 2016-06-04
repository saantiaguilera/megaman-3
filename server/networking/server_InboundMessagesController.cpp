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
#define MAX_MOVE_STATES 5

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
				std::cout << "Player name: " << inboundMessage << std::endl;
				NewPlayerSerializer newPlayerSerializer(inboundMessage);
				newPlayerSerializer.serialize();
				Engine::getInstance().getContext()->dispatchEvent(&newPlayerSerializer);
			}
			break;
		case START_GAME:
			if (Engine::getInstance().getPlayersList().size() < MAX_PLAYERS_COUNT){
				std::cout << "Start game!" << std::endl;
				// Set the flag of the engine to ready to start
				desiredPlayer = getDesiredPlayer(inboundMessage);
				if (desiredPlayer->isAdmin()){
					Engine::getInstance().setReadyToStart(true);
					StartGameSerializer startGameSerializer;
					startGameSerializer.serialize();
					Engine::getInstance().getContext()->dispatchEvent(&startGameSerializer);
				}
			}
			break;
		case KEY_PRESSED:
			std::cout << "Key Pressed!" << std::endl;
			// According to the pressed key we should do something
			// We should get the player id, the key pressed
			 desiredPlayer = getDesiredPlayer(inboundMessage);
			 processMovement(inboundMessage, desiredPlayer);
			 break;
		case WEAPON_CHANGE:
			std::cout << "Weapon change!" << std::endl;
			desiredPlayer = getDesiredPlayer(inboundMessage);
			desiredPlayer->getMegaman()->changeWeaponTo(processWeaponType(inboundMessage));
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

void InboundMessagesController::processMovement(const std::string& keyMap, Player* player) {
	std::stringstream ss;
	ss.str(keyMap);
//	bool jump, down, left, right, shoot;
	std::vector<bool> keysVector;
	bool aux;
	for (int i = 0; i < MAX_MOVE_STATES; ++i){
		ss >> aux;
		keysVector.push_back(aux);
	}

	if (keysVector[0] == true) {
		player->getMegaman()->move(PhysicObject::_moveState::MS_JUMP);
	}
	if (keysVector[1] == true) {
		player->getMegaman()->move(PhysicObject::_moveState::MS_DOWN);
	}
	if (keysVector[2] == true) {
		player->getMegaman()->move(PhysicObject::_moveState::MS_LEFT);
	}
	if (keysVector[3] == true) {
		player->getMegaman()->move(PhysicObject::_moveState::MS_RIGHT);
	}
	if (keysVector[4] == true) {
		player->getMegaman()->attack();
	}

}

int InboundMessagesController::processWeaponType(
		const std::string& weaponType) {
	std::stringstream ss(weaponType);
	int incomingWeaponType;
	ss >> incomingWeaponType;
	return incomingWeaponType;
}

InboundMessagesController::~InboundMessagesController() {
}

