/*
 * server_EventContext.h
 *
 *  Created on: Jun 1, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_EVENTCONTEXT_H_
#define SERVER_GAME_ENGINE_SERVER_EVENTCONTEXT_H_

#include <string>

class EventContext {
public:
	// Constructor
	EventContext();
	// Destroyer
	virtual ~EventContext();
	// Pure virtual method
	virtual void dispatchEvent(const std::string& event) = 0 ;
private:
	// Copy constructor
	EventContext(const EventContext&);
	// Assignment operator
	EventContext& operator=(const EventContext&);
};

#endif /* SERVER_GAME_ENGINE_SERVER_EVENTCONTEXT_H_ */
