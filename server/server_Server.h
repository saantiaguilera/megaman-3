/*
 * server_Server.h
 *
 *  Created on: Apr 23, 2016
 *      Author: mastanca
 */

#ifndef SRC_SERVER_SERVER_SERVER_H_
#define SRC_SERVER_SERVER_SERVER_H_

#include <string>
#include <vector>

#include "../common/common_Socket.h"
#include "networking/server_ClientProxy.h"

#define MAX_QUEUE_SIZE 128

class Server {
private:
	// Socket for incoming connections
	Socket dispatcherSocket;
	// Clients vector
	std::vector<ClientProxy*> clients;
	// Config filename
	std::string configFilename;

public:
	// Constructor
	explicit Server(const std::string& port, const std::string& configFilename);
	// Destroyer
	virtual ~Server();
	// This method encapsulates the server work
	// and calls the rest of the methods
	void run();

public:
	// Copy constructor
	Server(const Server&);
	// Assignment operator
	Server& operator=(const Server&);
};

#endif /* SRC_SERVER_SERVER_SERVER_H_ */
