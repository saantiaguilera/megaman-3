/*
 * server_iinboundMessageInterpreter.h
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#ifndef SERVER_NETWORKING_SERVER_INBOUNDMESSAGESCONTROLLER_H_
#define SERVER_NETWORKING_SERVER_INBOUNDMESSAGESCONTROLLER_H_

#include <string>

class InboundMessagesController {
private:
	// Determine the type of message by analizing its code
	void analizeMessageCode(int messageCode, const std::string& inboundMessage);
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
