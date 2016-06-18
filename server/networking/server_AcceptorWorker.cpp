/*
 * server_AcceptorWorker.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: mastanca
 */

#include "server_AcceptorWorker.h"

#include <iterator>

#include "../../common/common_Socket.h"
#include "../serializers/server_ConnectedPlayerSerializer.h"
#include "server_ReceiverWorker.h"

#define MAX_QUEUE_SIZE 128

AcceptorWorker::~AcceptorWorker() {
	// Free workers
	for (std::vector<Thread*>::iterator it = launchedThreads.begin();
			it != launchedThreads.end(); ++it) {
		delete (*it);
	}
	launchedThreads.clear();
}

void AcceptorWorker::run() {
	while (*keepOnListening) {
		ClientProxy* client = new ClientProxy;
		clients->push_back(client);
		client->acceptNewConnection(*dispatcherSocket);
		if (client->isConnected()) {
//			// Spawn a receiver worker
//			// It will call our client proxy's receive method
			ReceiverWorker* receiverWorker = new ReceiverWorker(client);
			launchedThreads.push_back(receiverWorker);
			receiverWorker->start();
		}
	}
}

void AcceptorWorker::terminate() {
	// This method was created to avoid the use of select, hoping it was
	// the best workaround
	// We simply call it when the server receives the STOP_LISTENING signal
	// It closes the dispatcher socket and joins the receiver threads
	dispatcherSocket->terminate();

	// We are done listening, so join my children
	for (std::vector<Thread*>::iterator it = launchedThreads.begin();
			it != launchedThreads.end(); ++it) {
		(*it)->join();
	}
	*keepOnListening = false;
}

AcceptorWorker::AcceptorWorker(Socket* dispatcherSocket, bool* keepOnListening,
		std::vector<ClientProxy*>* clients) :
		dispatcherSocket(dispatcherSocket), keepOnListening(keepOnListening), clients(
				clients) {
	dispatcherSocket->listen(MAX_QUEUE_SIZE);
}
