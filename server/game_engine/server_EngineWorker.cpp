/*
 * server_EngineRunner.cpp
 *
 *  Created on: Jun 20, 2016
 *      Author: mastanca
 */

#include "server_EngineWorker.h"

#include "server_Engine.h"

EngineWorker::EngineWorker(bool* running) : running(running) {

}

EngineWorker::~EngineWorker() {
}

void EngineWorker::run() {
	// Loop until game is ready to start, then start it
	while(!Engine::getInstance().isRunning() && *running){
		if(Engine::getInstance().isReadyToStart())
		Engine::getInstance().start();
	}
}
