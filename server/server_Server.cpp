/*
 * server_Server.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: mastanca
 */

#include "server_Server.h"

#include <iostream>
#include <iterator>

#include "game_engine/server_Engine.h"
#include "networking/server_AcceptorWorker.h"

#define STOP_LISTENING "q"

Server::~Server() {
	// Free client proxys
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
	AcceptorWorker acceptorWorker(&dispatcherSocket, &keepOnListening);
	acceptorWorker.start();
	Engine gameEngine;
	gameEngine.start();
	acceptorWorker.terminate();
	acceptorWorker.join();
}


void Server::releaseWorkers() {
//	// join workers
//	for (std::vector<Thread*>::iterator it = reducers.begin();
//			it != reducers.end(); ++it) {
//		(*it)->join();
//	}
//
//	// Free reducers
//	for (std::vector<Thread*>::iterator it = reducers.begin();
//			it != reducers.end(); ++it) {
//		delete (*it);
//	}
//	reducers.clear();
}
