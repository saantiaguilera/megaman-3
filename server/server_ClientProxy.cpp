/*
 * server_ClientProxy.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: mastanca
 */

#include "server_ClientProxy.h"

#include <syslog.h>
#include <cstring>
#include <errno.h>

#define MAX_BUFFER_SIZE 64
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
	bool keepReceiving = true;
	// Done workaround of size + 1 to avoid valgrind error
	char buffer[MAX_BUFFER_SIZE + 1];
	buffer[MAX_BUFFER_SIZE] = 0;
	while (keepReceiving) {
		memset(&buffer[0], 0, sizeof(buffer));
		if (socket.receive(&buffer[0], MAX_BUFFER_SIZE) == -1) {
			keepReceiving = false;
			syslog(LOG_ERR, "There was an error receiving from socket");
		} else {
			incomingData += buffer;
			// If we find an "End\n" client was done sending
			if (incomingData.find(STOP_RECEIVING_CONDITION)
					!= std::string::npos)
				keepReceiving = false;
		}
	}
	incomingData.erase(
			incomingData.length() - sizeof(STOP_RECEIVING_CONDITION) + 1,
			incomingData.length());
}

void ClientProxy::send(const std::string& data) {
	if (this->socket.send((char*) data.c_str(), data.length()) == -1) {
		syslog(LOG_ERR, "There was an error while sending data %s",
				strerror(errno));
	}
}
