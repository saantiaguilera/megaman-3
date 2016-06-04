/*
 * server_Server.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: mastanca
 */

#include "server_Server.h"

#include <iterator>

#include "game_engine/server_Engine.h"
#include "networking/server_AcceptorWorker.h"
#include "networking/server_SenderWorker.h"
#include "parsers/server_ConfigParser.h"
#include "server_Logger.h"

#define STOP_LISTENING "q"

Server::~Server() {
	// Free clients
	for (std::vector<ClientProxy*>::iterator it = clients.begin();
			it != clients.end(); ++it) {
		delete (*it);
	}
	clients.clear();
    Logger::getInstance().log(1, "Server quitting");
}

Server::Server(const std::string& port, const std::string& configFilename) : configFilename(configFilename) {
	dispatcherSocket = Socket(NULL, port.c_str());
	dispatcherSocket.bind();
}

void Server::run() {
	startGameEngine();
	bool keepOnListening = true;
	ConcurrentList<std::string> eventsQueue;
	AcceptorWorker acceptorWorker(&dispatcherSocket, &keepOnListening, &clients);
	acceptorWorker.start();
	SenderWorker senderWorker(&clients, &eventsQueue);
	senderWorker.start();

	// Set the context for dispatching events
	Engine::getInstance().setContext(&senderWorker);

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

void Server::startGameEngine(){
    ConfigParser configParser(configFilename);
    configParser.parseConfigDoc();
    // Initialize with configs set in config file
	Engine::getInstance().setGravity(configParser.getGravity());
	Engine::getInstance().setPositionIterations(configParser.getPositionIterations());
	Engine::getInstance().setVelocityIterations(configParser.getVelocityIterations());
	Engine::getInstance().setTimeStep(configParser.getTimestep());
	Engine::getInstance().setPlayerInitialLives(configParser.getPlayerInitialLives());
	Engine::getInstance().initializeWorld();
}
