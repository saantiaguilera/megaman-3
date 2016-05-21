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

Engine::Engine() {
}

void Engine::start() {
	// TODO: TESTING
    Met met;
	charactersList.push_back(&met);

	while(!quit){
		for (std::list<Character*>::iterator it = charactersList.begin();
				it != charactersList.end(); ++it) {
			(*it)->update();
		}
		sleep(1);
//		char response;
//		std::cout << "Wanna quit? (Y/n): ";
//		std::cin >> response;
//		if(response == 'y' || response == 'Y')
//			quit = true;
	}
}
