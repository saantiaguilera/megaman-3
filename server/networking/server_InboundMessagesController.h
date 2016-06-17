/*
 * server_iinboundMessageInterpreter.h
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#ifndef SERVER_NETWORKING_SERVER_INBOUNDMESSAGESCONTROLLER_H_
#define SERVER_NETWORKING_SERVER_INBOUNDMESSAGESCONTROLLER_H_

#include "../services/server_KeyMap.h"
#include <string>

class Player;

class InboundMessagesController {
private:
	int messageCode;
	unsigned int clientId;
	std::string inboundMessage;
	enum _moveKeyCode {
	MS_STOP,
	MS_LEFT,
	MS_RIGHT,
	MS_JUMP
	};

	KeyMap currentKeyMap;

	// Get the desired player
	Player* getDesiredPlayer(unsigned int playerId);
	// Get the movement from the input
	void processMovement(const std::string& keyMap, Player* player);
	// Get the weapon type
	int processWeaponType(const std::string& weaponType);
public:
	// Constructor
	InboundMessagesController();
	// Destroyer
	virtual ~InboundMessagesController();
	// Determine the type of message by analizing its code
	void analizeMessageCode();
	// Set parameters for analyzing
	void setParameters(int messageCode, unsigned int clientId, const std::string& inboundMessage);

private:
	// Copy constructor
	InboundMessagesController(const InboundMessagesController&);
	// Assignment operator
	InboundMessagesController& operator=(const InboundMessagesController&);
};

#endif /* SERVER_NETWORKING_SERVER_INBOUNDMESSAGESCONTROLLER_H_ */
