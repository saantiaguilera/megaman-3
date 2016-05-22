/*
 * server_Engine.cpp
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#include "server_Engine.h"

#include <unistd.h>

#include "../model/characters/mobs/server_Met.h"

Engine::~Engine() {
}

Engine::Engine() : quit(false){
}

Engine& Engine::getInstance() {
    static Engine instance;
    return instance;
}

void Engine::start() {
	// TODO: TESTING
	int i = 0;
    Met met;
	charactersList.push_back(&met);

	while(!quit){
		for (std::list<Character*>::iterator it = charactersList.begin();
				it != charactersList.end(); ++it) {
			(*it)->update();
		}
		sleep(1);
		++i;
		if (i == 120)
			quit = true;
//		char response;
//		std::cout << "Wanna quit? (Y/n): ";
//		std::cin >> response;
//		if(response == 'y' || response == 'Y')
//			quit = true;
	}
}
