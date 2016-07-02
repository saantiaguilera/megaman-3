/*
 * server_ReceiverWorker.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: mastanca
 */

#include <iostream>
#include <string>

#include "server_InboundMessagesController.h"

#include "server_ReceiverWorker.h"

ReceiverWorker::ReceiverWorker(ClientProxy* client) : client(client) {}

ReceiverWorker::~ReceiverWorker() {
}

void ReceiverWorker::run() {
	std::string inboundData;
	int messageCode;
	unsigned int messageLength;
	InboundMessagesController interpreter;
	while(client->isConnected()){
		client->receive(messageCode, messageLength, inboundData);
		interpreter.setParameters(messageCode, client->getId(), inboundData);
		interpreter.analizeMessageCode();
		inboundData = "";
	}
}
