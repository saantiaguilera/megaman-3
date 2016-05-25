/*
 * server_SenderWorker.h
 *
 *  Created on: May 25, 2016
 *      Author: mastanca
 */

#ifndef SERVER_NETWORKING_SERVER_SENDERWORKER_H_
#define SERVER_NETWORKING_SERVER_SENDERWORKER_H_

#include <string>

#include "../../common/common_ConcurrentList.h"
#include "../../common/common_Thread.h"

class ClientProxy;

class SenderWorker: public Thread {
private:
	// The client to send the data to
	ClientProxy* client;
	// The events list (Should be thread safe)
	// TODO: Maybe use an event class? (code, size, message)
	ConcurrentList<std::string> eventsList;
public:
	// Constructor
	SenderWorker(ClientProxy* client);
	// Destroyer
	virtual ~SenderWorker();
	// Run the worker
	void run();
	// Push an event to send
	void pushEvent(const std::string& event);
};

#endif /* SERVER_NETWORKING_SERVER_SENDERWORKER_H_ */
