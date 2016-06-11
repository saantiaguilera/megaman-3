/*
 * server_Projectile.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Projectile.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <Dynamics/b2World.h>
#include <stddef.h>

#include "../../game_engine/server_Engine.h"
#include "../../game_engine/server_EventContext.h"
#include "../../serializers/server_MovementSerializer.h"

Projectile::~Projectile() {
	myBody->GetWorld()->DestroyBody(myBody);
}

Projectile::Projectile(unsigned int damage, projectile_types_t type, float32 x, float32 y, int facingPosition) : PhysicObject(), initialX(x), initialY(y), facingPosition(facingPosition) {
	PROJECTILE_TYPE = type;
	this->damage = damage;
}

int Projectile::getProjectileType() const {
	return PROJECTILE_TYPE;
}

unsigned int Projectile::getDamage() const {
	return damage;
}

int Projectile::getObjectType() {
//	return OT_PROJECTILE;
	return 30;
}

void Projectile::setBody() {
	b2BodyDef projectileBodyDef;
	projectileBodyDef.type = b2_kinematicBody;
	projectileBodyDef.position.Set(initialX,initialY);
	// TODO: Maybe add it from the outside? when its created
	// Set it as bullet (it adds heavy workload, check if neccessary)
	projectileBodyDef.bullet = true;
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&projectileBodyDef);

	// Add shape to bodysetBody
	b2PolygonShape boxShape;
	boxShape.SetAsBox(BODIES_SIZE/2,BODIES_SIZE/2);
	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);

	// Apply an impulse <-- this direction
	// TODO: Set it in constructor?
	if (facingPosition > 0){
		myBody->SetLinearVelocity(b2Vec2(5,0));
	} else {
		myBody->SetLinearVelocity(b2Vec2(-5,0));
	}
	myBody->SetGravityScale(0);

	notify();
}

void Projectile::setUserData() {
	// Assign user data for callbacks
	myBody->SetUserData( this );
}

void Projectile::update() {
	if (myBody != NULL){
//		move(1);
		MovementSerializer* serializer = new MovementSerializer(getId(), getPositionX(), getPositionY());
		Engine::getInstance().getContext()->dispatchEvent(serializer);
	}
}
