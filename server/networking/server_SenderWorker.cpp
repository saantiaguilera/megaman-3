/*
 * server_SenderWorker.cpp
 *
 *  Created on: May 25, 2016
 *      Author: mastanca
 */

#include "server_SenderWorker.h"

SenderWorker::SenderWorker(ClientProxy* client) : client(client) {}

SenderWorker::~SenderWorker() {
}

void SenderWorker::run(){
}

void SenderWorker::pushEvent(const std::string& event) {
	eventsList.add(event);
}
