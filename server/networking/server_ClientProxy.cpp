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
#include <cstring>
#include <iostream>

#define MAX_BUFFER_SIZE 10

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

void ClientProxy::receive(int& messageCode, unsigned int& messageLength, std::string& incomingData) {
	// Receive message code
	socket.receive((char*) &messageCode, sizeof(int));
	// TODO: Log receive error
	messageCode = ntohl(messageCode);

	// Receive message length
	socket.receive((char*) &messageLength, sizeof(unsigned int));
	// TODO: Log receive error
	messageLength = ntohl(messageLength);

	// Done workaround of size + 1 to avoid valgrind error
	char* buffer = new char[messageLength + 1];
	buffer[messageLength] = 0;
	memset(&buffer[0], 0, sizeof(*buffer));
	if (socket.receive(&buffer[0], messageLength) == -1) {
		syslog(LOG_ERR, "There was an error receiving from socket");
	} else {
		incomingData += buffer;
	}
}

void ClientProxy::send(const std::string& data) {
	if (this->socket.send((char*) data.c_str(), data.length()) == -1) {
		syslog(LOG_ERR, "There was an error while sending data %s",
				strerror(errno));
	}
}
