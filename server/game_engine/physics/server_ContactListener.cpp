/*
 * server_ContactListener.cpp
 *
 *  Created on: May 27, 2016
 *      Author: mastanca
 */

#include "server_ContactListener.h"

ContactListener::ContactListener() {

}

ContactListener::~ContactListener() {
}

void BeginContact(b2Contact* contact) {

  //check if fixture A was a ball
  void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
  if ( bodyUserData->getObjectType() )
    static_cast<Ball*>( bodyUserData )->startContact();
  // TODO: Here make use of double dispatch for collisions

  //check if fixture B was a ball
  bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
  if ( bodyUserData )
    static_cast<Ball*>( bodyUserData )->startContact();

}

