/*
 * server_PhysicObject.cpp
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#include "server_PhysicObject.h"

#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <stddef.h>

#include "../../serializers/server_MovementSerializer.h"
#include "../../serializers/server_ObjectCreationSerializer.h"
#include "../server_Engine.h"
#include "../server_EventContext.h"

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
      case MS_DOWN:  desiredVely =  -5; break;
      case MS_RIGHT: desiredVelx =  5; break;
      case MS_JUMP: desiredVely = 5; break;
    }
    float velChangex = desiredVelx - vel.x;
    float impulsex = myBody->GetMass() * velChangex; //disregard time factor
    float velChangey = desiredVely - vel.y;
    float impulsey = myBody->GetMass() * velChangey; //disregard time factor
    myBody->ApplyLinearImpulse( b2Vec2(impulsex,impulsey), myBody->GetWorldCenter(), true );

	MovementSerializer* serializer = new MovementSerializer(getId(), getPositionX(), getPositionY());
	Engine::getInstance().getContext()->dispatchEvent(serializer);
}

void PhysicObject::handleCollisionWith(PhysicObject* objectCollidedWith) {
	// Does nothing
}

void PhysicObject::handleStopCollidingWith(PhysicObject* objectCollidedWith) {
	// Does nothing
}

b2Body* PhysicObject::getMyBody() const {
	return myBody;
}

float PhysicObject::getPositionX() const {
	return myBody->GetPosition().x;
}

void PhysicObject::notify() {
	ObjectCreationSerializer* objectCreationSerializer = new ObjectCreationSerializer(this);
	Engine::getInstance().getContext()->dispatchEvent(objectCreationSerializer);
}

float PhysicObject::getPositionY() const {
	return myBody->GetPosition().y;
}
