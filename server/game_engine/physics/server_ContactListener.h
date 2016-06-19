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
private:
	void* bodyUserDataA;
	void* bodyUserDataB;
	void analyzeFeetContact(b2Contact* contact, int changeFactor);
public:
	// Constructor
	ContactListener();
	// Destroyer
	virtual ~ContactListener();
	// Begin contact callback method, is called when contact is generated
	void BeginContact(b2Contact* contact);
	// End contact callback method, called when contact is finished
	void EndContact(b2Contact* contact);
	// Handle contact function is called inside callback methods
	void getBodyUserDataForContact(b2Contact* contact);
private:
	// Copy constructor
	ContactListener(const ContactListener&);
	// Assignment operator
	ContactListener& operator=(const ContactListener&);
};

#endif /* SERVER_GAME_ENGINE_PHYSICS_SERVER_CONTACTLISTENER_H_ */
