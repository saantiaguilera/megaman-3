/*
 * server_ClientProxy.h
 *
 *  Created on: Apr 23, 2016
 *      Author: mastanca
 */

#ifndef SRC_SERVER_SERVER_CLIENTPROXY_H_
#define SRC_SERVER_SERVER_CLIENTPROXY_H_

#include "../common/common_Socket.h"
#include <string>

class ClientProxy {
private:
	// Flag to check status of the socket
	bool connected;
	// The actual socket
	Socket socket;
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
	void receive(std::string& incomingData);
};

#endif /* SRC_SERVER_SERVER_CLIENTPROXY_H_ */
