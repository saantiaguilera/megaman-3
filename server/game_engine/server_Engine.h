/*
 * server_Engine.h
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_ENGINE_H_
#define SERVER_GAME_ENGINE_SERVER_ENGINE_H_

#include <Common/b2Settings.h>
#include <list>
#include <string>
#include <vector>

#include "../../common/common_Mutex.h"
#include "physics/server_PhysicObject.h"
#include "server_Player.h"

#include "physics/server_ContactListener.h"
#include "server_EventContext.h"

#include <Dynamics/b2World.h>

class Engine {
	// Singleton
private:
	// Mutex for locking shared resources
	Mutex mutex;
	// Keep running flag
	bool quit;
	// Flag to mark engine ready to start
	// Used as signal for main thread
	bool readyToStart;
	// Flag for checking if engine is running
	bool running;
	// A thread safe list for holding characters
	std::vector<PhysicObject*> updatablesList;
	// A list holding the players
	std::vector<Player*>  playersList;
	// box2dWorld for physics
	b2World* myWorld;
	// Timestep for box2d
	float32 timeStep;
	// Game gravity
	float32 gravity;
	// velocity iterations for box2d
	int32 velocityIterations;
	// positions iterations for box2d
	int32 positionIterations;
	// contact listener for collisions
	ContactListener* contactListener;
	// Set containing elements to destroy betweeen steps
	std::vector<PhysicObject*> objectsToDestroy;
	// Vector containing elements to create betweeen steps
	std::vector<PhysicObject*> objectsToCreate;
	// Player lives intial
	unsigned int playerInitialLives;
	// Context for sending messages
	EventContext* context;
	// Current map identifier, to grab the corresponding boss chamber
	int currentMapId;
	// Iterate over the to create list and create the bodies
	void createObjects();
	// Iterate over the to destroy list and destroy the bodies
	void destroyObjects();
	// Teleport to boss chamber was activated?
	bool teleportToBossChamberWasActivated = false;
	// Flag indicating if loots should appear
	bool forceLoot = true;

	void cleanEngine();
public:
	// Return logger instance
	static Engine& getInstance();
	// Destroyer
	virtual ~Engine();
	// Get started
	void start();
	// Add new player to the game
	void addNewPlayer(unsigned int id, const std::string& name);
	// Return players list
	const std::vector<Player*>& getPlayersList();
	// Tell if game has finished
	bool isFinished();
	// Is engine ready to start?
	bool isReadyToStart() const;
	// Set the status of the flag
	void setReadyToStart(bool readyToStart);
	// Is engine running?
	bool isRunning() const;
	// Return the world
	b2World* getMyWorld();
	// Add new object for deletion
	void markObjectForRemoval(PhysicObject* objectToMark);
	// Add new object for creation
	void markObjectForCreation(PhysicObject* objectToMark);
	// Set game gravity
	void setGravity(float32 gravity);
	// Set position iterations
	void setPositionIterations(int32 positionIterations);
	// Set timestep
	void setTimeStep(float32 timeStep);
	// Set velocity iterations
	void setVelocityIterations(int32 velocityIterations);
	// Set player initial lives
	void setPlayerInitialLives(unsigned int playerInitialLives);
	// Initialize engines world
	void initializeWorld();
	// Get current context
	EventContext* getContext();
	// Set the context for dispatching events
	void setContext(EventContext* context);
	// Teleport to boss map
	void teleportToBossChamber();
	// Return the current selected map id
	int getCurrentMapId() const;
	// Set the current map id
	void setCurrentMapId(int currentMapId);
	// Return list of updatables
	std::vector<PhysicObject*>* getUpdatablesList();
	// Set the flag for teleporting to boss chamber
	void activateTeleportToBossChamber();
	void setQuit(bool quit);
	bool isTeleportToBossChamberActivated() const;
	bool isForceLoot() const;

private:
	// Constructor
	Engine();
	// Copy constructor
	Engine(const Engine&);
	// Assignment operator
	Engine& operator=(const Engine&);
};

#endif /* SERVER_GAME_ENGINE_SERVER_ENGINE_H_ */
