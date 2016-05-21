/*
 * server_Engine.h
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_ENGINE_H_
#define SERVER_GAME_ENGINE_SERVER_ENGINE_H_

#include <list>

#include "../model/characters/server_Character.h"

class Engine {
private:
	// Keep running flag
	bool quit;
	// A thread safe list for holding characters
	std::list<Character*> charactersList;
public:
	// Constructor
	Engine();
	// Destroyer
	virtual ~Engine();
	// Get started
	void start();
private:
	// Copy constructor
	Engine(const Engine&);
	// Assignment operator
	Engine& operator=(const Engine&);
};

#endif /* SERVER_GAME_ENGINE_SERVER_ENGINE_H_ */
