/*
 * server_Server.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: mastanca
 */

#include "server_Server.h"

#include <iostream>
#include <iterator>

#include "../common/common_ConcurrentList.h"
#include "../common/common_Serializer.h"
#include "game_engine/server_Engine.h"
#include "game_engine/server_EngineWorker.h"
#include "networking/server_AcceptorWorker.h"
#include "networking/server_SenderWorker.h"
#include "parsers/server_ConfigParser.h"
#include "server_Logger.h"

class EngineWorker;

#define STOP_LISTENING 'q'

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
	char input;
	initializeGameEngine();
	bool keepOnListening = true;
	bool engineRunning = true;
	ConcurrentList<Serializer*> eventsQueue;
	AcceptorWorker acceptorWorker(&dispatcherSocket, &keepOnListening, &clients);
	acceptorWorker.start();
	SenderWorker senderWorker(&clients, &eventsQueue);
	senderWorker.start();

	// Set the context for dispatching events
	Engine::getInstance().setContext(&senderWorker);

	EngineWorker engineWorker(&engineRunning);
	engineWorker.start();

	while (keepOnListening){
		std::cin >> input;
		if (input == STOP_LISTENING)
			keepOnListening = false;
	}

	engineRunning = false;

	senderWorker.setKeepRunning(false);
	acceptorWorker.terminate();
	acceptorWorker.join();
	senderWorker.join();
	engineWorker.join();
}

void Server::initializeGameEngine(){
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
