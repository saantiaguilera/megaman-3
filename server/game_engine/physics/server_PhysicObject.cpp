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

PhysicObject::PhysicObject() : myBody(NULL), numFootContacts(0), updatable(false), vulnerable(true), ticksTillVulnerable(0), facingPosition(OR_RIGHT) {
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

    float desiredVelx = vel.x;
    float desiredVely = vel.y;

    switch ( moveState ) {
    	case MS_LEFT:  desiredVelx = -STEP_LENGTH; facingPosition = OR_LEFT; break;//let speed change gradually
    	case MS_STOP:  desiredVelx = 0; break;//let speed decay gradually
		case MS_RIGHT: desiredVelx = STEP_LENGTH; facingPosition = OR_RIGHT; break;//let speed change gradually
    	case MS_JUMP: if ( numFootContacts < 1 ) break; desiredVely = BODIES_SIZE*10; break;//let speed change gradually
    	case MS_DOWN: if (myBody->GetGravityScale() == 0) desiredVely = -5; break;
    }
    float velChangex = desiredVelx - vel.x;
    float impulsex = myBody->GetMass() * velChangex;
    float velChangey = desiredVely - vel.y;
    float impulsey = myBody->GetMass() * velChangey;

    bool moving = moveState == MS_LEFT || moveState == MS_RIGHT || moveState == MS_JUMP || moveState == MS_DOWN || desiredVely != 0 || moveState == MS_STOP_JUMPING;
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
	// Does nothing, redefined in projectiles, powerups
}

void PhysicObject::setUserData() {
	// Do nothing, redefined in projectiles, powerups
}

void PhysicObject::update() {
}

bool PhysicObject::isUpdatable() const {
	return updatable;
}

void PhysicObject::setUpdatable(bool updatable) {
	this->updatable = updatable;
}

bool PhysicObject::isVulnerable() const {
	return vulnerable;
}

void PhysicObject::setVulnerable(bool vulnerable) {
	this->vulnerable = vulnerable;
	ticksTillVulnerable = TICKS_TILL_VULNERABLE_DEFAULT;
}

bool PhysicObject::isJumping() {
	return numFootContacts == 0;
}
