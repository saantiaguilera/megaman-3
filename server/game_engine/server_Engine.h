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

#include "../model/characters/server_Character.h"
#include "server_Player.h"
#include "server_EventContext.h"
#include "../../common/common_Mutex.h"

class b2World;
class ContactListener;

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
	std::list<Character*> charactersList;
	// A list holding the players
	std::list<Player*>  playersList;
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
	// Player lives intial qty
	unsigned int playerInitialLives;
	// Context for sending messages
	EventContext* context;

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
	const std::list<Player*>& getPlayersList();
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
	EventContext* getContext();
	void setContext(EventContext* context);

private:
	// Constructor
	Engine();
	// Copy constructor
	Engine(const Engine&);
	// Assignment operator
	Engine& operator=(const Engine&);
};

#endif /* SERVER_GAME_ENGINE_SERVER_ENGINE_H_ */
