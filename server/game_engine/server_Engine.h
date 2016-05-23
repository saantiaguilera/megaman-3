/*
 * server_Engine.h
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_ENGINE_H_
#define SERVER_GAME_ENGINE_SERVER_ENGINE_H_

#include <list>
#include <string>

#include "../model/characters/server_Character.h"
#include "server_Player.h"

class Engine {
	// Singleton
private:
	// Keep running flag
	bool quit;
	// A thread safe list for holding characters
	std::list<Character*> charactersList;
	// A list holding the players
	std::list<Player*>  playersList;
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

private:
	// Constructor
	Engine();
	// Copy constructor
	Engine(const Engine&);
	// Assignment operator
	Engine& operator=(const Engine&);
};

#endif /* SERVER_GAME_ENGINE_SERVER_ENGINE_H_ */
