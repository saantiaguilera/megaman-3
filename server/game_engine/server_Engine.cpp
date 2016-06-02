/*
 * server_Engine.cpp
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#include "server_Engine.h"

#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2World.h>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "../model/characters/humanoids/server_Megaman.h"
#include "../model/projectiles/server_Bomb.h"
#include "../serializers/server_MovementSerializer.h"
#include "../serializers/server_ObjectDestructionSerializer.h"
#include "../server_Logger.h"
#include "physics/server_ContactListener.h"

Engine::~Engine() {
	for (std::list<Player*>::iterator it = playersList.begin();
			it != playersList.end(); ++it) {
		delete *it;
	}

	delete contactListener;
	delete myWorld;
    Logger::getInstance().log(1, "Engine quitting");
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

void Engine::markObjectForRemoval(PhysicObject* objectToMark) {
	objectsToDestroy.push_back(objectToMark);
	ObjectDestructionSerializer objectDestructionSerializer(objectToMark->getId(), objectToMark->getMyBody()->GetPosition().x, objectToMark->getMyBody()->GetPosition().y);
	// TODO: Add to events queue
}

void Engine::setPlayerInitialLives(unsigned int playerInitialLives) {
	this->playerInitialLives = playerInitialLives;
}

Engine::Engine() : quit(false), readyToStart(false), running(false), contactListener(NULL){}

Engine& Engine::getInstance() {
    static Engine instance;
    return instance;
}

void Engine::start() {
    Logger::getInstance().log(1, "Game engine started");
	running = true;
	// TODO: TESTING
	int i = 0;
//    Met met;
//	charactersList.push_back(&met);
	Player aPlayer("Lan Hikari", playerInitialLives);
	charactersList.push_back(aPlayer.getMegaman());
	Bomb* aBomb = new Bomb(0,-5);
	aBomb->getMyBody()->SetAwake(false);

	while(!quit){
		myWorld->Step( timeStep, velocityIterations, positionIterations);
		for (std::list<Character*>::iterator it = charactersList.begin();
				it != charactersList.end(); ++it) {
			(*it)->update();
			// TODO: For testing events queue
			// TODO: MAKE A METHOD IN PHYSIC OBJECT TO GET THE POSITION TO NOT VIOLATE ENCAPSULATION
			MovementSerializer serializer((*it)->getId(), (*it)->getMyBody()->GetPosition().x, (*it)->getMyBody()->GetPosition().y);
			serializer.serialize();
			context->dispatchEvent(serializer.getSerialized());
			// TODO: Who should add the event to the events list? Yes, inside the update method
		}
		//process elements for deletion
		std::vector<PhysicObject*>::iterator it = objectsToDestroy.begin();
		std::vector<PhysicObject*>::iterator end = objectsToDestroy.end();
		for (; it != end; ++it) {
			PhysicObject* objectToDelete = *it;

			//delete object... physics body is destroyed here
			delete objectToDelete;

			//... and remove it from main list of objects
			std::list<Character*>::iterator it = std::find(charactersList.begin(), charactersList.end(), objectToDelete);
			if ( it != charactersList.end() )
			  charactersList.erase( it );
		}

		//clear this list for next time
		objectsToDestroy.clear();
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
	playersList.push_back(new Player(name, playerInitialLives));
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

void Engine::setGravity(float32 gravity) {
	this->gravity = gravity;
}

void Engine::setPositionIterations(int32 positionIterations) {
	this->positionIterations = positionIterations;
}

void Engine::setTimeStep(float32 timeStep) {
	this->timeStep = timeStep;
}

void Engine::setVelocityIterations(int32 velocityIterations) {
	this->velocityIterations = velocityIterations;
}

void Engine::initializeWorld(){
	b2Vec2 gravity(0, this->gravity); //normal earth gravity, 9.8 m/s^2 straight down!
	myWorld = new b2World(gravity);

	// Create contact listener for world
	contactListener = new ContactListener();
	myWorld->SetContactListener(contactListener);

	// TODO: Read them from config file
	timeStep = this->timeStep;      //the length of time passed to simulate (seconds)
	velocityIterations = this->velocityIterations;   //how strongly to correct velocity
	positionIterations = this->positionIterations;   //how strongly to correct position
}

EventContext* Engine::getContext() const {
	return context;
}

void Engine::setContext(EventContext* context) {
	this->context = context;
}
