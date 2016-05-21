/*
 * server_ClientProxy.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: mastanca
 */

#include "server_ClientProxy.h"

#include <errno.h>
#include <netinet/in.h>
#include <syslog.h>
#include <cstdint>
#include <cstring>
#include <iostream>

#define MAX_BUFFER_SIZE 10
#define STOP_RECEIVING_CONDITION "End\n"

ClientProxy::ClientProxy() {
	connected = false;
	socket = Socket();
}

bool ClientProxy::isConnected() const {
	return connected;
}

ClientProxy::~ClientProxy() {
}

void ClientProxy::acceptNewConnection(const Socket& dispatcherSocket) {
	if (dispatcherSocket.accept(&socket) == 0) {
		connected = true;
	}
}

void ClientProxy::receive(std::string& incomingData) {
	// Receive message code
	uint32_t messageCode;
	socket.receive((char*) &messageCode, sizeof(uint32_t));
	// TODO: Log receive error
	messageCode = ntohl(messageCode);
	std::cout << messageCode << std::endl;

	// Receive message length
	uint32_t messageLength;
	socket.receive((char*) &messageLength, sizeof(uint32_t));
	// TODO: Log receive error
	messageLength = ntohl(messageLength);
	std::cout << messageLength << std::endl;

	// Done workaround of size + 1 to avoid valgrind error
	char* buffer = new char[messageLength + 1];
	buffer[messageLength] = 0;
	memset(&buffer[0], 0, sizeof(*buffer));
	if (socket.receive(&buffer[0], MAX_BUFFER_SIZE) == -1) {
		syslog(LOG_ERR, "There was an error receiving from socket");
	} else {
		incomingData += buffer;
		std::cout << incomingData << std::endl;
	}
}

void ClientProxy::send(const std::string& data) {
	if (this->socket.send((char*) data.c_str(), data.length()) == -1) {
		syslog(LOG_ERR, "There was an error while sending data %s",
				strerror(errno));
	}
}
