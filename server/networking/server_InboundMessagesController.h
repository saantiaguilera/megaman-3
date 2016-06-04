/*
 * server_iinboundMessageInterpreter.h
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#ifndef SERVER_NETWORKING_SERVER_INBOUNDMESSAGESCONTROLLER_H_
#define SERVER_NETWORKING_SERVER_INBOUNDMESSAGESCONTROLLER_H_

#include <string>

class Player;

class InboundMessagesController {
private:
	enum _moveKeyCode {
	MS_STOP,
	MS_LEFT,
	MS_RIGHT,
	MS_JUMP
	};
	// Determine the type of message by analizing its code
	void analizeMessageCode(int messageCode, const std::string& inboundMessage);
	// Get the desired player
	Player* getDesiredPlayer(const std::string& playerId);
	// Get the movement from the input
	void processMovement(const std::string& keyMap, Player* player);
	// Get the weapon type
	int processWeaponType(const std::string& weaponType);
public:
	// Constructor
	InboundMessagesController(int messageCode, const std::string& inboundMessage);
	// Destroyer
	virtual ~InboundMessagesController();

private:
	// Copy constructor
	InboundMessagesController(const InboundMessagesController&);
	// Assignment operator
	InboundMessagesController& operator=(const InboundMessagesController&);
};

#endif /* SERVER_NETWORKING_SERVER_INBOUNDMESSAGESCONTROLLER_H_ */
