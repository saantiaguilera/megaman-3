/*
 * server_Engine.cpp
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2World.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

#include "../../common/common_MapConstants.h"
#include "../parsers/server_JsonMapParser.h"
#include "../serializers/server_ObjectCreationSerializer.h"
#include "../serializers/server_ObjectDestructionSerializer.h"
#include "../server_Logger.h"

#include "server_Engine.h"

Engine::~Engine() {
	for (std::vector<Player*>::iterator it = playersList.begin();
			it != playersList.end(); ++it) {
		delete *it;
	}

	delete contactListener;
	delete myWorld;

	Logger::getInstance().log(1, "Engine quitting");
}

const std::vector<Player*>& Engine::getPlayersList() {
	return playersList;
}

bool Engine::isRunning() const {
	return running;
}

b2World* Engine::getMyWorld() {
	return myWorld;
}

void Engine::markObjectForRemoval(PhysicObject* objectToMark) {
	bool isInList = false;

	for (PhysicObject * obj : objectsToDestroy) {
		if (obj->getId() == objectToMark->getId()) {
			isInList = true;
			break;
		}
	}

	if (!isInList) {
		mutex.lock();
		objectsToDestroy.push_back(objectToMark);
		mutex.unlock();
	}
}

void Engine::setPlayerInitialLives(unsigned int playerInitialLives) {
	this->playerInitialLives = playerInitialLives;
}

void Engine::teleportToBossChamber() {
	for ( b2Body* b = myWorld->GetBodyList(); b; b = b->GetNext()){
		PhysicObject* object = static_cast<PhysicObject*>(b->GetUserData());
	  if (object->getTypeForSerialization() != ObstacleViewTypeMegaman){
		  markObjectForRemoval(object);
	  }
	}

	JsonMapParser mapParser;
	std::stringstream ss;
	ss << currentMapId;
	mapParser.parseDocument("bosschamber" + ss.str() + ".json");
}

void Engine::createObjects() {
	//process elements for creation
	std::vector<PhysicObject*>::iterator it = objectsToCreate.begin();
	std::vector<PhysicObject*>::iterator end = objectsToCreate.end();
	for (; it != end; ++it) {
		if (!myWorld->IsLocked()){
			PhysicObject* objectToCreate = *it;
			objectToCreate->setBody();
			objectToCreate->setUpdatable(true);
			updatablesList.push_back(objectToCreate);
			std::cout << "Object created: " << (*it)->getId() << " " <<(*it)->getTypeForSerialization() << std::endl;
			ObjectCreationSerializer* objectCreationSerializer = new ObjectCreationSerializer(objectToCreate);
			context->dispatchEvent(objectCreationSerializer);
		}
	}
	//clear this list for next time
	objectsToCreate.clear();
}

void Engine::destroyObjects() {
	//process elements for deletion
	std::vector<PhysicObject*>::iterator it = objectsToDestroy.begin();
	std::vector<PhysicObject*>::iterator end = objectsToDestroy.end();
	for (; it != end; ++it) {
		if (!myWorld->IsLocked() && (*it) != NULL){
			PhysicObject* objectToDelete = *it;
			std::cout << "Object destroyed: " << (*it)->getId() << " " <<(*it)->getTypeForSerialization() << std::endl;
			ObjectDestructionSerializer* objectDestructionSerializer = new ObjectDestructionSerializer((*it)->getId(), (*it)->getPositionX(), (*it)->getPositionY());
			context->dispatchEvent(objectDestructionSerializer);

			//delete object... physics body is destroyed here
			myWorld->DestroyBody(objectToDelete->getMyBody());

			//... and remove it from main list of objects
			std::vector<PhysicObject*>::iterator it = std::find(updatablesList.begin(), updatablesList.end(), objectToDelete);
			if ( it != updatablesList.end() )
				updatablesList.erase( it );

			delete objectToDelete;
			objectToDelete = NULL;
		}
	}
	//clear this list for next time
	objectsToDestroy.clear();
}

int Engine::getCurrentMapId() const {
	return currentMapId;
}

void Engine::setCurrentMapId(int currentMapId) {
	this->currentMapId = currentMapId;
}

void Engine::markObjectForCreation(PhysicObject* objectToMark) {
	bool isInList = false;

	for (PhysicObject * obj : objectsToCreate) {
		if (obj->getId() == objectToMark->getId()) {
			isInList = true;
			break;
		}
	}

	if (!isInList) {
		mutex.lock();
		objectsToCreate.push_back(objectToMark);
		mutex.unlock();
	}
}

std::vector<PhysicObject*>* Engine::getUpdatablesList() {
	return &updatablesList;
}

Engine::Engine() : quit(false), readyToStart(false), running(false), contactListener(NULL){}

Engine& Engine::getInstance() {
    static Engine instance;
    return instance;
}

void Engine::start() {
	Logger::getInstance().log(1, "Game engine started");
	running = true;

	while(!quit){
		createObjects();
		myWorld->Step( timeStep, velocityIterations, positionIterations);
		// For updating AI and movements of bullets
		for (PhysicObject * object : updatablesList) {
			if (object->isUpdatable()){
				object->update();
			}
		}
		destroyObjects();
		usleep(timeStep*1000000*1.4);
	}
}

void Engine::addNewPlayer(unsigned int id, const std::string& name) {
	mutex.lock();
	playersList.push_back(new Player(id, name, playerInitialLives));
	mutex.unlock();
}

bool Engine::isFinished() {
	return quit;
}

bool Engine::isReadyToStart() const {
	return readyToStart;
}

void Engine::setReadyToStart(bool readyToStart) {
	mutex.lock();
	this->readyToStart = readyToStart;
	mutex.unlock();
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

	timeStep = this->timeStep;      //the length of time passed to simulate (seconds)
	velocityIterations = this->velocityIterations;   //how strongly to correct velocity
	positionIterations = this->positionIterations;   //how strongly to correct position
}

EventContext* Engine::getContext() {
	return context;
}

void Engine::setContext(EventContext* context) {
	this->context = context;
}
