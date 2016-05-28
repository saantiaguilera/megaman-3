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

#include "server_PhysicObject.h"

ContactListener::ContactListener() {

}

ContactListener::~ContactListener() {
}

void ContactListener::BeginContact(b2Contact* contact) {
	  //Grab fixtureA body, then object associated
	  void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	  //Grab fixtureB body, then object associated
	  void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

	  static_cast<PhysicObject*>(bodyUserDataA)->handleCollisionWith(static_cast<PhysicObject*>(bodyUserDataB));
	  static_cast<PhysicObject*>(bodyUserDataB)->handleCollisionWith(static_cast<PhysicObject*>(bodyUserDataA));

	  // TODO: Here make use of double dispatch for collisions

}
