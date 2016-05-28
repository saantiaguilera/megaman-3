/*
 * server_Engine.cpp
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#include "server_Engine.h"

#include <Common/b2Math.h>
#include <Dynamics/b2World.h>
#include <iostream>

#include "../model/characters/humanoids/server_Megaman.h"
#include "../model/projectiles/server_Bomb.h"
#include "physics/server_ContactListener.h"

Engine::~Engine() {
	for (std::list<Player*>::iterator it = playersList.begin();
			it != playersList.end(); ++it) {
		delete *it;
	}

	delete contactListener;
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

	// Create contact listener for world
	contactListener = new ContactListener();
	myWorld->SetContactListener(contactListener);

	// TODO: Read them from config file
	timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
	velocityIterations = 8;   //how strongly to correct velocity
	positionIterations = 3;   //how strongly to correct position

	// TODO: Setting a floor for testing
	// TODO: Needs collision filtering
//	b2BodyDef floorBodyDef;
//	floorBodyDef.type = b2_staticBody;
//	floorBodyDef.position.Set(0,-1);
//	b2FixtureDef floorFixtureDef;
//	b2EdgeShape edgeShape;
//	edgeShape.Set( b2Vec2(-15,0), b2Vec2(15,0) );
//
//	floorFixtureDef.shape = &edgeShape;
//
//	b2Body* floorBody = myWorld->CreateBody(&floorBodyDef);
//	floorBody->CreateFixture(&floorFixtureDef);

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
//    Met met;
//	charactersList.push_back(&met);
	Megaman megaman(0,0);
	charactersList.push_back(&megaman);
	Bomb aBomb(0,-5);

	while(!quit){
		myWorld->Step( timeStep, velocityIterations, positionIterations);
		for (std::list<Character*>::iterator it = charactersList.begin();
				it != charactersList.end(); ++it) {
			(*it)->update();
			// TODO: Who should add the event to the events list?
		}
//		sleep(1);
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
