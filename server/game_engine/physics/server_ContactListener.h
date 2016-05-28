/*
 * server_ContactListener.h
 *
 *  Created on: May 27, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_PHYSICS_SERVER_CONTACTLISTENER_H_
#define SERVER_GAME_ENGINE_PHYSICS_SERVER_CONTACTLISTENER_H_

#include <Dynamics/b2WorldCallbacks.h>

class ContactListener: public b2ContactListener {
public:
	// Constructor
	ContactListener();
	// Destroyer
	virtual ~ContactListener();
	// Begin contact callback function, is called when contact is generated
	void BeginContact(b2Contact* contact);
private:
	// Copy constructor
	ContactListener(const ContactListener&);
	// Assignment operator
	ContactListener& operator=(const ContactListener&);
};

#endif /* SERVER_GAME_ENGINE_PHYSICS_SERVER_CONTACTLISTENER_H_ */
