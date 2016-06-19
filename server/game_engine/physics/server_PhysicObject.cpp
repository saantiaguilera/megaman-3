/*
 * server_PhysicObject.cpp
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */
#include <stddef.h>
#include <iostream>

#include "../../serializers/server_MovementSerializer.h"
#include "../../serializers/server_ObjectCreationSerializer.h"
#include "../server_Engine.h"
#include "../server_EventContext.h"

#include "server_PhysicObject.h"

// Initialize ids value
unsigned int PhysicObject::globalCount = 0;

PhysicObject::PhysicObject() : myBody(NULL), numFootContacts(0), updatable(false), facingPosition(OR_RIGHT) {
	++globalCount;
	id = globalCount;
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

    switch ( moveState ) {
    	case MS_LEFT:  desiredVelx = -STEP_LENGTH; facingPosition = OR_LEFT; break;//let speed change gradually
    	case MS_STOP:  desiredVelx =  vel.x * 0; desiredVely = vel.y * 0.98; break;//let speed decay gradually
		case MS_RIGHT: desiredVelx = STEP_LENGTH; facingPosition = OR_RIGHT; break;//let speed change gradually
    	case MS_JUMP: desiredVely = 10; break;//let speed change gradually
    	case MS_DOWN: desiredVely = -5; break;
    }
    float velChangex = desiredVelx - vel.x;
    float impulsex = myBody->GetMass() * velChangex;
    float velChangey = desiredVely - vel.y;
    float impulsey = myBody->GetMass() * velChangey;

    bool moving = moveState == MS_LEFT || moveState == MS_RIGHT || moveState == MS_JUMP || moveState == MS_DOWN;
    setUpdatable(moving);

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

void PhysicObject::setBody() {
	// Does nothing, redefined in projectiles
}

void PhysicObject::setUserData() {
	// Do nothing, redefined in projectiles
}

void PhysicObject::update() {
//	std::cout << "Inside update" << std::endl;
//	if (myBody != NULL){
//		std::cout << "Body position: "  << myBody->GetPosition().x << ", " << myBody->GetPosition().y << std::endl;
//		MovementSerializer* serializer = new MovementSerializer(getId(), getPositionX(), getPositionY());
////		std::cout << "Movement serializer created" << std::endl;
//		Engine::getInstance().getContext()->dispatchEvent(serializer);
//	}
}

bool PhysicObject::isUpdatable() const {
	return updatable;
}

void PhysicObject::setUpdatable(bool updatable) {
	this->updatable = updatable;
}
