/*
 * server_EngineRunner.cpp
 *
 *  Created on: Jun 20, 2016
 *      Author: mastanca
 */

#include "server_EngineWorker.h"

#include <iostream>

#include "server_Engine.h"

EngineWorker::EngineWorker(bool* running) : running(running) {

}

EngineWorker::~EngineWorker() {
}

void EngineWorker::run() {
	// Loop until game is ready to start, then start it
	while(!Engine::getInstance().isRunning() && *running){
		std::unique_lock<std::mutex> lock(mutex);
		conditionVariable.wait(lock);
		if(Engine::getInstance().isReadyToStart())
			Engine::getInstance().start();
	}
}

void EngineWorker::notify() {
	std::unique_lock<std::mutex> lock(mutex);
	conditionVariable.notify_all();
}
