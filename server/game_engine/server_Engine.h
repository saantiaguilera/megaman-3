/*
 * server_Engine.h
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_ENGINE_H_
#define SERVER_GAME_ENGINE_SERVER_ENGINE_H_

#include <Box2D/Box2D.h>
#include <list>
#include <string>

#include "../model/characters/server_Character.h"
#include "server_Player.h"

class Engine {
	// Singleton
private:
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
public:
	// Return logger instance
	static Engine& getInstance();
	// Destroyer
	virtual ~Engine();
	// Get started
	void start();
	// Add new player to the game
	void addNewPlayer(const std::string& name);
	// Return players list
	const std::list<Player*>& getPlayersList() const;
	// Tell if game has finished
	bool isFinished();
	// Is engine ready to start?
	bool isReadyToStart() const;
	// Set the status of the flag
	void setReadyToStart(bool readyToStart);
	// Is engine running?
	bool isRunning() const;

private:
	// Constructor
	Engine();
	// Copy constructor
	Engine(const Engine&);
	// Assignment operator
	Engine& operator=(const Engine&);
};

#endif /* SERVER_GAME_ENGINE_SERVER_ENGINE_H_ */
