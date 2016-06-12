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
#include <iostream>

#include "../../serializers/server_MovementSerializer.h"
#include "../../serializers/server_ObjectCreationSerializer.h"
#include "../server_Engine.h"
#include "../server_EventContext.h"

#define STEP_LENGTH 5

// Initialize ids value
unsigned int PhysicObject::id = 0;

PhysicObject::PhysicObject() : myBody(NULL), numFootContacts(0), facingPosition(FS_LEFT) {
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
      case MS_LEFT:  desiredVelx = -STEP_LENGTH; facingPosition = FS_LEFT; break;
      case MS_DOWN:  desiredVely =  -STEP_LENGTH; break;
      case MS_RIGHT: desiredVelx =  STEP_LENGTH; facingPosition = FS_RIGHT; break;
      case MS_JUMP: desiredVely = STEP_LENGTH; break;
    }
    float velChangex = desiredVelx - vel.x;
    float impulsex = myBody->GetMass() * velChangex; //disregard time factor
    float velChangey = desiredVely;
//    float impulsey = myBody->GetMass() * velChangey; //disregard time factor
	float impulsey = 1 * velChangey; //disregard time factor
    std::cout << this->getPositionX() << ", " << this->getPositionY() << std::endl;
    myBody->ApplyLinearImpulse( b2Vec2(impulsex, impulsey), myBody->GetWorldCenter(), true );
    std::cout << this->getPositionX() << ", " << this->getPositionY() << std::endl;

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

void PhysicObject::setBody() {
	// Does nothing, redefined in projectiles
}

void PhysicObject::setUserData() {
	// Do nothing, redefined in projectiles
}

void PhysicObject::update() {
//	if (myBody != NULL){
//		std::cout << "Body position: "  << myBody->GetPosition().x << ", " << myBody->GetPosition().y << std::endl;
//		MovementSerializer* serializer = new MovementSerializer(getId(), getPositionX(), getPositionY());
//		std::cout << "Movement serializer created" << std::endl;
//		Engine::getInstance().getContext()->dispatchEvent(serializer);
//	}
}
