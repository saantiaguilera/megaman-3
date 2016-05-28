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

PhysicObject::PhysicObject() : myBody(NULL) {
	++id;
}

unsigned int PhysicObject::getId() const {
	return id;
}

PhysicObject::~PhysicObject() {
}

void PhysicObject::move(unsigned int moveState) {
    b2Vec2 vel = myBody->GetLinearVelocity();
    float desiredVel = 0;
    switch ( moveState )
    {
      case MS_LEFT:  desiredVel = -5; break;
      case MS_STOP:  desiredVel =  0; break;
      case MS_RIGHT: desiredVel =  5; break;
    }
    float velChange = desiredVel - vel.x;
    float impulse = myBody->GetMass() * velChange; //disregard time factor
    myBody->ApplyLinearImpulse( b2Vec2(impulse,0), myBody->GetWorldCenter(), true );
}
