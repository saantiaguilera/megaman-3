/*
 * server_SenderWorker.h
 *
 *  Created on: May 25, 2016
 *      Author: mastanca
 */

#ifndef SERVER_NETWORKING_SERVER_SENDERWORKER_H_
#define SERVER_NETWORKING_SERVER_SENDERWORKER_H_

#include <string>
#include <vector>
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable>

#include "../../common/common_ConcurrentList.h"
#include "../../common/common_Serializer.h"
#include "../../common/common_Thread.h"
#include "../game_engine/server_EventContext.h"
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable>
#include "server_ClientProxy.h"

class SenderWorker: public Thread, public EventContext {
private:
	// The clients to send the data to
	std::vector<ClientProxy*>* clients;
	// The events list (Should be thread safe)
	// TODO: Maybe use an event class? (code, size, message)
	ConcurrentList<Serializer*>* eventsQueue;
	// Keep on running?
	bool keepRunning;
	// Mutex for conditional variable
	std::mutex mutex;
	// Condition variable to not fry the cpu looking for evens
	std::condition_variable conditionVariable;
	// Signal for resuming thread
	bool ready = false;
public:
	// Constructor
	SenderWorker(std::vector<ClientProxy*>* clients, ConcurrentList<Serializer*>* eventsQueue);
	// Destroyer
	virtual ~SenderWorker();
	// Run the worker
	void run();
	// Push an event
	virtual void dispatchEvent(Serializer* event);
	// Push an event to a specific client
	virtual void dispatchEventTo(Serializer* event, unsigned int clientId);
	// Toogle keep running
	void setKeepRunning(bool keepRunning);
};

#endif /* SERVER_NETWORKING_SERVER_SENDERWORKER_H_ */
