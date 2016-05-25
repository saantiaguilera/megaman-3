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
		TSQueue<std::string>* eventsQueue) :
		clients(clients), eventsQueue(eventsQueue), keepRunning(true) {
}

SenderWorker::~SenderWorker() {
}

void SenderWorker::run() {
	while (keepRunning){
		for (std::vector<ClientProxy*>::iterator it = clients->begin();
				it != clients->end(); ++it) {
			if (eventsQueue->getQueue()->size() == 0){
				continue;
			} else {
				(*it)->send(eventsQueue->pop_front());
			}
		}
		sleep(0.1);
	}
}

void SenderWorker::pushEvent(const std::string& event) {
	eventsQueue->push_back(event);
}

void SenderWorker::setKeepRunning(bool keepRunning) {
	this->keepRunning = keepRunning;
}
