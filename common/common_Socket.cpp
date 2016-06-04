/*
 * Socket.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: mastanca
 */

#include "common_Socket.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <syslog.h>
#include <iostream>

Socket::Socket(char* ip, const char* port) {
	build(ip, port);
}

Socket::~Socket() {
	terminate();
}

void Socket::build(char *ip, const char *port) {
	int s = 0;
	struct addrinfo hints;
	int flag = 0;
	active = true;

	if (ip == NULL) {
		flag = AI_PASSIVE; // Flag for server
	}
	// Port is received as a parameter from user, no need to convert to net
	const char* serviceName = port;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET; /* IPv4 (or AF_INET6 for IPv6)     */
	hints.ai_socktype = SOCK_STREAM; /* TCP  (or SOCK_DGRAM for UDP)    */
	hints.ai_flags = flag; /* 0 (or AI_PASSIVE for server)           */

	s = getaddrinfo(ip, serviceName, &hints, &(this->result));

	if (s != 0) {
		syslog(LOG_ERR, "There was an error when creating socket, "
				"getaddrinfo returned %d: %s", s, gai_strerror(s));
		active = false;
	}

	this->fd = socket(this->result->ai_family, this->result->ai_socktype,
			this->result->ai_protocol);

	// TODO: Erase before production
	int optval = 1;
	setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

	if (this->fd == -1) {
		syslog(LOG_ERR, "There was an error when creating socket, "
				"socket fd was -1");
		active = false;
	}
}

bool Socket::isActive() {
	return active;
}

int Socket::terminate() {
	shutdown(this->fd, SHUT_RDWR);
	if (fd != -1)
		close(this->fd);

	active = false;
	return EXIT_SUCCESS;
}

int Socket::bind() {
	// WEIRD bug here, if used the socket fd it fails
	int anotherfd = socket(this->result->ai_family, this->result->ai_socktype,
			this->result->ai_protocol);
	this->fd = anotherfd;

	// TODO: Erase before production
	int optval = 1;
	setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

	if (::bind(this->fd, this->result->ai_addr, this->result->ai_addrlen)
			== -1) {
		close(this->fd);
		syslog(LOG_ERR, "There was an error when binding the socket, "
				"bind returned -1: %s", strerror(errno));
		freeaddrinfo(this->result);
		active = false;
		return EXIT_FAILURE;
	}
	freeaddrinfo(this->result);
	return EXIT_SUCCESS;
}

int Socket::listen(int maxQueueSize) {
	if (::listen(this->fd, maxQueueSize) == -1) {
		syslog(LOG_ERR, "There was an error when listening, "
				"listen returned -1");
		active = false;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int Socket::accept(Socket* client) const {
	client->fd = ::accept(this->fd, NULL, NULL);
	if (client->fd == -1) {
		syslog(LOG_ERR, "There was an error when accepting a new client, "
				"accept returned -1");
		client->active = false;
		return EXIT_FAILURE;
	}
	client->active = true;
	return EXIT_SUCCESS;
}

int Socket::connect() {
	int s = 0;
	struct addrinfo *ptr;
	bool are_we_connected = false;
	for (ptr = this->result; ptr != NULL && are_we_connected == false;
			ptr = ptr->ai_next) {
		s = ::connect(this->fd, ptr->ai_addr, ptr->ai_addrlen);
		if (s == -1) {
			close(this->fd);
			this->fd = socket(ptr->ai_family, ptr->ai_socktype,
					ptr->ai_protocol);
		}
		are_we_connected = (s != -1);
	}
	freeaddrinfo(this->result);
	if (are_we_connected == false) {
		active = false;
		syslog(LOG_ERR, "There was an error when connecting");
		return EXIT_FAILURE;
	}
	active = true;
	return EXIT_SUCCESS;
}

int Socket::receive(char* buffer, int size) {
	int received = 0;
	int response = 0;
	bool is_a_valid_socket = true;
	bool closed_socket = false;

	while (received < size && is_a_valid_socket && !closed_socket) {
		response = recv(this->fd, &buffer[received], size - received,
				MSG_NOSIGNAL);

		if (response == 0) {
			// Socket was closed
			closed_socket = true;
			syslog(LOG_INFO, "Socket was closed");
			active = false;
		} else if (response < 0) {
			// There was an error
			is_a_valid_socket = false;
			syslog(LOG_WARNING,
					"There was an error when receiving data from socket ");
		} else {
			received += response;
		}
	}

	if (is_a_valid_socket) {
		active = true;
		return received;
	} else {
		active = false;
		return -EXIT_FAILURE;
	}
}

Socket::Socket() {
	result = NULL;
	fd = -1;
}

int Socket::send(char* buffer, int size) {
	int sent = 0;
	int response = 0;
	bool is_a_valid_socket = true;

	while (sent < size && is_a_valid_socket) {
		response = ::send(this->fd, &buffer[sent], size - sent, MSG_NOSIGNAL);

		if (response == 0) {
			// Socket was closed
			is_a_valid_socket = false;
			syslog(LOG_WARNING,
					"There was an error when sending data from socket, "
							"socket was closed");
		} else if (response < 0) {
			// There was an error
			is_a_valid_socket = false;
			syslog(LOG_ERR,
					"There was an error when receiving data from socket ");
		} else {
			sent += response;
		}
	}

	if (is_a_valid_socket) {
		active = true;
		return sent;
	} else {
		active = false;
		return -EXIT_FAILURE;
	}
}
