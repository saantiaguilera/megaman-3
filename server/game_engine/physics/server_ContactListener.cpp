/*
 * server_ContactListener.cpp
 *
 *  Created on: May 27, 2016
 *      Author: mastanca
 */

#include "server_ContactListener.h"

#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <Dynamics/Contacts/b2Contact.h>
#include <stddef.h>
#include <iostream>

#include "server_PhysicObject.h"

ContactListener::ContactListener() : bodyUserDataA(NULL), bodyUserDataB(NULL) {

}

ContactListener::~ContactListener() {
}

void ContactListener::BeginContact(b2Contact* contact) {
	std::cout << "Collision detected!" << std::endl;
	getBodyUserDataForContact(contact);

	static_cast<PhysicObject*>(bodyUserDataA)->handleCollisionWith(static_cast<PhysicObject*>(bodyUserDataB));
	static_cast<PhysicObject*>(bodyUserDataB)->handleCollisionWith(static_cast<PhysicObject*>(bodyUserDataA));
}

void ContactListener::EndContact(b2Contact* contact) {
	getBodyUserDataForContact(contact);

	static_cast<PhysicObject*>(bodyUserDataA)->handleStopCollidingWith(static_cast<PhysicObject*>(bodyUserDataB));
	static_cast<PhysicObject*>(bodyUserDataB)->handleStopCollidingWith(static_cast<PhysicObject*>(bodyUserDataA));
}

void ContactListener::getBodyUserDataForContact(b2Contact* contact) {
	  //Grab fixtureA body, then object associated
	  bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	  //Grab fixtureB body, then object associated
	  bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
}
