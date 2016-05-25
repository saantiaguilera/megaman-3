/*
 * server_SenderWorker.h
 *
 *  Created on: May 25, 2016
 *      Author: mastanca
 */

#ifndef SERVER_NETWORKING_SERVER_SENDERWORKER_H_
#define SERVER_NETWORKING_SERVER_SENDERWORKER_H_

#include <string>

#include "../../common/common_Thread.h"
#include "../../common/common_TSQueue.h"

class ClientProxy;

class SenderWorker: public Thread {
private:
	// The clients to send the data to
	std::vector<ClientProxy*>* clients;
	// The events list (Should be thread safe)
	// TODO: Maybe use an event class? (code, size, message)
	TSQueue<std::string>* eventsQueue;
	// Keep on running?
	bool keepRunning;
public:
	// Constructor
	SenderWorker(std::vector<ClientProxy*>* clients, TSQueue<std::string>* eventsQueue);
	// Destroyer
	virtual ~SenderWorker();
	// Run the worker
	void run();
	// Push an event to send
	void pushEvent(const std::string& event);
	// Toogle keep running
	void setKeepRunning(bool keepRunning);
};

#endif /* SERVER_NETWORKING_SERVER_SENDERWORKER_H_ */
