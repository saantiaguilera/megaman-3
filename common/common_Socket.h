/*
 * Socket.h
 *
 *  Created on: Apr 17, 2016
 *      Author: mastanca
 */

#ifndef SRC_SOCKETS_COMMON_SOCKET_H_
#define SRC_SOCKETS_COMMON_SOCKET_H_

#include <string>

struct addrinfo;

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 1
#endif

class Socket {
private:
	int fd;
	struct addrinfo* result;
	bool active = false;
public:
	// Simple constructor
	Socket();
	// Initiates with given parameters
	Socket(char* ip, const char* port);
	// Free's socket resources
	virtual ~Socket();
	//Prepares the socket for the given params
	void build(char *ip, const char *port);
	// Binds the socket to a connection
	int bind();
	// Listens for new connections, up to max queue size (blocker)
	int listen(int maxQueueSize);
	// Accepts new connection
	int accept(Socket* client) const;
	// Connects to server (blocker)
	int connect();
	// Receives size bytes from the net
	int receive(char* buffer, int size);
	// Sends size bytes over the net
	int send(char* buffer, int size);
	// Closes socket
	int terminate();

	bool isActive();
};

#endif /* SRC_SOCKETS_COMMON_SOCKET_H_ */
