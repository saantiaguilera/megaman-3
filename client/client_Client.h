/*
 * client_Client.h
 *
 *  Created on: May 16, 2016
 *      Author: santi
 */

#ifndef CLIENT_CLIENT_CLIENT_H_
#define CLIENT_CLIENT_CLIENT_H_

#include "concurrent/client_Looper.h"

/**
 * Pasar a cpp
 */
bool quit = false;

class Client {
public:
	Client() { /* DO SMTH */ };
	~Client() { /* DO SMTH  */};

	void start() {
		while (!quit) {
			while (Looper::getMainLooper().get() != NULL) {
				//Do something with the event
				Runnable *runnable = Looper::getMainLooper().get();

				Looper::getMainLooper().pop();

				(*runnable)(); //You are thinking "Ewww whats this ??" Its operator()() !
			}
		}
	}
private:
	Client(const Client&);
	Client& operator=(const Client&);
};



#endif /* CLIENT_CLIENT_CLIENT_H_ */
