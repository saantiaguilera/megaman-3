/*
 * server_Engine.cpp
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#include "server_Engine.h"

#include <unistd.h>
#include <iostream>

#include "../model/characters/mobs/server_Met.h"

Engine::~Engine() {
	for (std::list<Player*>::iterator it = playersList.begin();
			it != playersList.end(); ++it) {
		delete *it;
	}

	delete myWorld;
}

const std::list<Player*>& Engine::getPlayersList() const {
	return playersList;
}

bool Engine::isRunning() const {
	return running;
}

b2World* Engine::getMyWorld() const {
	return myWorld;
}

Engine::Engine() : quit(false), readyToStart(false), running(false){
	b2Vec2 gravity(0, -9.8); //normal earth gravity, 9.8 m/s^2 straight down!
	myWorld = new b2World(gravity);

	float32 timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
	int32 velocityIterations = 8;   //how strongly to correct velocity
	int32 positionIterations = 3;   //how strongly to correct position

	myWorld->Step( timeStep, velocityIterations, positionIterations);
}

Engine& Engine::getInstance() {
    static Engine instance;
    return instance;
}

void Engine::start() {
	std::cout << "Begin game " << std::endl;
	running = true;
	// TODO: TESTING
	int i = 0;
    Met met;
	charactersList.push_back(&met);

	while(!quit){
		for (std::list<Character*>::iterator it = charactersList.begin();
				it != charactersList.end(); ++it) {
			(*it)->update();
			// TODO: Who should add the event to the events list?
		}
		sleep(1);
		++i;
//		if (i == 10)
//			quit = true;
		if ( i % 10 == 0){
			// TODO: For debugging
			char response;
			std::cout << "Wanna quit? (Y/n): ";
			std::cin >> response;
			if(response == 'y' || response == 'Y')
				quit = true;
		}

	}
}

void Engine::addNewPlayer(const std::string& name) {
	playersList.push_back(new Player(name));
}

bool Engine::isFinished() {
	return quit;
}

bool Engine::isReadyToStart() const {
	return readyToStart;
}

void Engine::setReadyToStart(bool readyToStart) {
	this->readyToStart = readyToStart;
}
