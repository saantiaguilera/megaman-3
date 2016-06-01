/*
 * server_SenderWorker.cpp
 *
 *  Created on: May 25, 2016
 *      Author: mastanca
 */

#include "server_SenderWorker.h"

#include <unistd.h>
#include <iterator>
#include <queue>
#include <vector>

#include "server_ClientProxy.h"

SenderWorker::SenderWorker(std::vector<ClientProxy*>* clients,
		ConcurrentList<std::string>* eventsQueue) :
		clients(clients), eventsQueue(eventsQueue), keepRunning(true) {
}

SenderWorker::~SenderWorker() {
}

void SenderWorker::run() {
	while (keepRunning){
		for (std::vector<ClientProxy*>::iterator it = clients->begin();
				it != clients->end(); ++it) {
			if (eventsQueue->size() == 0){
				continue;
			} else {
				(*it)->send(eventsQueue->pop_front());
			}
		}
		sleep(0.1);
	}
}

void SenderWorker::setKeepRunning(bool keepRunning) {
	this->keepRunning = keepRunning;
}

void SenderWorker::dispatchEvent(const std::string& event) {
	eventsQueue->add(event);
}
