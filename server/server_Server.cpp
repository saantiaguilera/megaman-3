/*
 * server_Server.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: mastanca
 */

#include "server_Server.h"

#include <iterator>

#include "../common/common_TSQueue.h"
#include "game_engine/server_Engine.h"
#include "networking/server_AcceptorWorker.h"
#include "networking/server_SenderWorker.h"

#define STOP_LISTENING "q"

Server::~Server() {
	// Free clients
	for (std::vector<ClientProxy*>::iterator it = clients.begin();
			it != clients.end(); ++it) {
		delete (*it);
	}
	clients.clear();
}

Server::Server(const std::string& port) {
	dispatcherSocket = Socket(NULL, port.c_str());
	dispatcherSocket.bind();
}

void Server::run() {
//	callAcceptorWorker();
	bool keepOnListening = true;
	TSQueue<std::string> eventsList;
	AcceptorWorker acceptorWorker(&dispatcherSocket, &keepOnListening, &clients);
	acceptorWorker.start();
	SenderWorker senderWorker(&clients, &eventsList);
	senderWorker.start();

	// Loop until game is ready to start, then start it
	while(!Engine::getInstance().isRunning()){
		if(Engine::getInstance().isReadyToStart())
			Engine::getInstance().start();
	}

	senderWorker.setKeepRunning(false);
	acceptorWorker.terminate();
	acceptorWorker.join();
	senderWorker.join();
}
