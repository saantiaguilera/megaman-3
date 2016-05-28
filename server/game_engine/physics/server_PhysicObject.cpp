/*
 * server_PhysicObject.cpp
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#include "server_PhysicObject.h"

#include <Dynamics/b2Body.h>

// Initialize ids value
unsigned int PhysicObject::id = 0;

PhysicObject::PhysicObject() : myBody(NULL), numFootContacts(0) {
	++id;
}

unsigned int PhysicObject::getId() const {
	return id;
}

PhysicObject::~PhysicObject() {
}

void PhysicObject::move(unsigned int moveState) {
    b2Vec2 vel = myBody->GetLinearVelocity();
    float desiredVelx = 0;
    float desiredVely = 0;
    switch ( moveState )
    {
      case MS_LEFT:  desiredVelx = -5; break;
      case MS_STOP:  desiredVelx =  0; break;
      case MS_RIGHT: desiredVelx =  5; break;
      case MS_JUMP: desiredVely = 5; break;
    }
    float velChangex = desiredVelx - vel.x;
    float impulsex = myBody->GetMass() * velChangex; //disregard time factor
    float velChangey = desiredVely - vel.y;
    float impulsey = myBody->GetMass() * velChangey; //disregard time factor
    myBody->ApplyLinearImpulse( b2Vec2(impulsex,impulsey), myBody->GetWorldCenter(), true );
}
