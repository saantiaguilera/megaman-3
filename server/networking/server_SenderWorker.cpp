/*
 * server_SenderWorker.cpp
 *
 *  Created on: May 25, 2016
 *      Author: mastanca
 */

#include "server_SenderWorker.h"

#include <iostream>
#include <iterator>

SenderWorker::SenderWorker(std::vector<ClientProxy*>* clients,
		ConcurrentList<Serializer*>* eventsQueue) :
		clients(clients), eventsQueue(eventsQueue), keepRunning(true) {
}

SenderWorker::~SenderWorker() {
}

void SenderWorker::run() {
	while(keepRunning){
		if (eventsQueue->size() != 0){
			Serializer* event = eventsQueue->pop_front();

			if (event->getDispatchAll()) {
				for (std::vector<ClientProxy*>::iterator it = clients->begin();
				it != clients->end(); ++it){
					(*it)->send(event);
				}
			} else {
				dispatchEventTo(event, event->getDispatchClientID());
			}

			delete event;
		}
	}
}

void SenderWorker::setKeepRunning(bool keepRunning) {
	this->keepRunning = keepRunning;
}

void SenderWorker::dispatchEvent(Serializer* event) {
	eventsQueue->add(event);
}

void SenderWorker::dispatchEventTo(Serializer* event,
		unsigned int clientId) {
	for (std::vector<ClientProxy*>::iterator it = clients->begin();
		it != clients->end(); ++it){
		if ((*it)->getId() == clientId)
			(*it)->send(event);
	}
}
