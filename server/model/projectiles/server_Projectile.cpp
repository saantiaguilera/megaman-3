/*
 * server_Projectile.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Projectile.h"

#include <Collision/Shapes/b2CircleShape.h>
#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <Dynamics/b2World.h>
#include <stddef.h>

#include "../../game_engine/server_Engine.h"
#include "../../game_engine/server_EventContext.h"
#include "../../serializers/server_MovementSerializer.h"

#define PROJECTILE_COLLISION_FILTERING_GROUP -2

Projectile::Projectile(unsigned int damage, projectile_types_t type, float32 x,
		float32 y, ORIENTATION facingPosition) :
		PhysicObject(), initialX(x), initialY(y), facingPosition(facingPosition) {
	PROJECTILE_TYPE = type;
	this->damage = damage;
}

Projectile::~Projectile() {
	Engine::getInstance().getMyWorld()->DestroyBody(getMyBody());
}

int Projectile::getProjectileType() const {
	return PROJECTILE_TYPE;
}

unsigned int Projectile::getDamage() const {
	return damage;
}

int Projectile::getObjectType() {
	return OT_PROJECTILE;
}

void Projectile::setBody() {
	b2BodyDef projectileBodyDef;
	projectileBodyDef.type = b2_dynamicBody;

	int vx = 0, vy = 0;
	//TODO Maybe you plan on customizing this ?
	switch (facingPosition) {
	case OR_RIGHT:
		vx = STEP_LENGTH;
		initialX += getWidth()*2;
		break;
	case OR_LEFT:
		vx = -STEP_LENGTH;
		initialX -= getWidth()*2;
		break;
	case OR_BOTTOM:
		vy = -STEP_LENGTH;
		initialY -= getHeight();
		break;
	case OR_TOP:
		vy = STEP_LENGTH;
		initialY += getHeight();
		break;
	}

	projectileBodyDef.position.Set(initialX, initialY);
	// TODO: Maybe add it from the outside? when its created
	// Set it as bullet (it adds heavy workload, check if neccessary)
	projectileBodyDef.bullet = true;
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&projectileBodyDef);

	myBody->SetUserData(this);

	// Add shape to bodysetBody
	b2CircleShape circleShape;
	circleShape.m_radius = getWidth();

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &circleShape;
	boxFixtureDef.density = 1;
	boxFixtureDef.filter.groupIndex = PROJECTILE_COLLISION_FILTERING_GROUP;
	myBody->CreateFixture(&boxFixtureDef);

	myBody->SetLinearVelocity(b2Vec2(vx, vy));
	myBody->SetGravityScale(0);
	if (bouncy)
		myBody->GetFixtureList()->SetRestitution(1);

	notify();
}

float32 Projectile::getWidth() {
	return BODIES_SIZE / 2;
}

void Projectile::move(int facingPosition) {
	b2Vec2 vel = myBody->GetLinearVelocity();

	float desiredVelx = 0;
	float desiredVely = 0;

	switch (facingPosition) {
	case OR_LEFT:
		desiredVelx = -STEP_LENGTH*2;
		break;	//let speed change gradually
	case OR_RIGHT:
		desiredVelx = STEP_LENGTH*2;
		break;	//let speed change gradually
	case OR_TOP:
		desiredVely = BODIES_SIZE * 8;
		break;	//let speed change gradually
	case OR_BOTTOM:
		desiredVely = -5;
		break;
	}
	float velChangex = desiredVelx - vel.x;
	float impulsex = myBody->GetMass() * velChangex;
	float velChangey = desiredVely - vel.y;
	float impulsey = myBody->GetMass() * velChangey;

	bool moving = facingPosition == OR_LEFT || facingPosition == OR_RIGHT
			|| facingPosition == OR_TOP || facingPosition == OR_BOTTOM
			|| desiredVely != 0;
	setUpdatable(moving);

	myBody->ApplyLinearImpulse(b2Vec2(impulsex, impulsey),
			myBody->GetWorldCenter(), true);

	MovementSerializer* serializer = new MovementSerializer(getId(),
			getPositionX(), getPositionY());
	Engine::getInstance().getContext()->dispatchEvent(serializer);
}

float32 Projectile::getHeight() {
	return BODIES_SIZE / 2;
}

void Projectile::setUserData() {
	// Assign user data for callbacks
	myBody->SetUserData(this);
}

void Projectile::update() {
	if (myBody != NULL) {
		move(facingPosition);
	}
}
