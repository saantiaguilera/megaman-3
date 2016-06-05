/*
 * server_ReceiverWorker.h
 *
 *  Created on: Apr 24, 2016
 *      Author: mastanca
 */

#ifndef SRC_SERVER_SERVER_RECEIVERWORKER_H_
#define SRC_SERVER_SERVER_RECEIVERWORKER_H_

#include "../../common/common_Thread.h"

class ClientProxy;

class ReceiverWorker: public Thread {
private:
	// The client that will receive data (has the socket inside)
	ClientProxy* client;

public:
	// Constructor
	ReceiverWorker(ClientProxy* client);
	// Destroyer
	virtual ~ReceiverWorker();
	// Run the worker
	void run();
};

#endif /* SRC_SERVER_SERVER_RECEIVERWORKER_H_ */
