/*
 * server_ClientProxy.h
 *
 *  Created on: Apr 23, 2016
 *      Author: mastanca
 */

#ifndef SRC_SERVER_SERVER_CLIENTPROXY_H_
#define SRC_SERVER_SERVER_CLIENTPROXY_H_

#include <string>

#include "../../common/common_Socket.h"

class Serializer;

class ClientProxy {
private:
	// Global count of the clients
	static unsigned int globalCount;
	// Id of the player
	unsigned int id;
	// Flag to check status of the socket
	bool connected;
	// The actual socket
	Socket socket;
	// Check result of send
	void checkConnection(int sendResult);
public:
	// Constructor
	ClientProxy();
	//Destroyer
	virtual ~ClientProxy();
	// Returns whether the socket is connected or not
	bool isConnected() const;
	// Accepts new connection, setting the new socket to his own
	void acceptNewConnection(const Socket& dispatcherSocket);
	// Receives incomingData from the net
	void receive(int& messageCode, unsigned int& messageLength, std::string& incomingData);
	// Sends data over the net, through the socket
	void send(Serializer* serializer);
	// Return my id
	unsigned int getId() const;
};

#endif /* SRC_SERVER_SERVER_CLIENTPROXY_H_ */
