/*
 * server_AcceptorWorker.h
 *
 *  Created on: Apr 24, 2016
 *      Author: mastanca
 */

#ifndef SRC_SERVER_SERVER_ACCEPTORWORKER_H_
#define SRC_SERVER_SERVER_ACCEPTORWORKER_H_

#include <vector>

#include "../../common/common_Thread.h"
#include "server_ClientProxy.h"

class Socket;

class AcceptorWorker: public Thread {
private:
	// Clients references vector
	std::vector<ClientProxy*> clients;
	// References to launched threads
	std::vector<Thread*> launchedThreads;
	// The main socket from the server, from who we will listen
	Socket* dispatcherSocket;
	// Flag to continue listening
	bool* keepOnListening;
public:
	// Constructor
	AcceptorWorker(Socket* dispatcherSocket, bool* keepOnListening);
	// Destroyer
	virtual ~AcceptorWorker();
	// Run the worker
	void run();
	// Terminates worker, freeing resources
	void terminate();
};

#endif /* SRC_SERVER_SERVER_ACCEPTORWORKER_H_ */
