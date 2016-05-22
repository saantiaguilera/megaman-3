/*
 * server_iinboundMessageInterpreter.h
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#ifndef SERVER_NETWORKING_SERVER_INBOUNDMESSAGEINTERPRETER_H_
#define SERVER_NETWORKING_SERVER_INBOUNDMESSAGEINTERPRETER_H_

#include <string>

class InboundMessageInterpreter {
private:
	// Determine the type of message by analizing its code
	void analizeMessageCode(int messageCode, const std::string& inboundMessage);
public:
	// Constructor
	InboundMessageInterpreter(int messageCode, const std::string& inboundMessage);
	// Destroyer
	virtual ~InboundMessageInterpreter();

private:
	// Copy constructor
	InboundMessageInterpreter(const InboundMessageInterpreter&);
	// Assignment operator
	InboundMessageInterpreter& operator=(const InboundMessageInterpreter&);
};

#endif /* SERVER_NETWORKING_SERVER_INBOUNDMESSAGEINTERPRETER_H_ */
