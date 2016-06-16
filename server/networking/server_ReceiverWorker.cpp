/*
 * server_ReceiverWorker.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: mastanca
 */

#include "server_ReceiverWorker.h"

#include <iostream>
#include <string>

#include "server_ClientProxy.h"
#include "server_InboundMessagesController.h"

ReceiverWorker::ReceiverWorker(ClientProxy* client) : client(client) {}

ReceiverWorker::~ReceiverWorker() {
}

void ReceiverWorker::run() {
	std::string inboundData;
	int messageCode;
	unsigned int messageLength;
	while(client->isConnected()){
		client->receive(messageCode, messageLength, inboundData);
		std::cout << "Received: " << inboundData << std::endl;
		InboundMessagesController interpreter(messageCode, client->getId(), inboundData);
		inboundData = "";
	}
}
