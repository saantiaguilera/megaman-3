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

#include "../../game_engine/server_Engine.h"

Projectile::~Projectile() {
	myBody->GetWorld()->DestroyBody(myBody);
}

Projectile::Projectile(unsigned int damage, projectile_types_t type, float32 x, float32 y) : PhysicObject() {
	PROJECTILE_TYPE = type;
	this->damage = damage;

	b2BodyDef projectileBodyDef;
	projectileBodyDef.type = b2_kinematicBody;
	projectileBodyDef.position.Set(x,y);
	// TODO: Maybe add it from the outside? when its created
	// Set it as bullet (it adds heavy workload, check if neccessary)
	projectileBodyDef.bullet = true;
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&projectileBodyDef);

	// Assign user data for callbacks
	myBody->SetUserData( this );

	// Add shape to body
	// TODO: remove hardcoded parameters
	b2PolygonShape boxShape;
	boxShape.SetAsBox(1,1);

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);

	// Apply an impulse <-- this direction
	// TODO: Set it in constructor?
	myBody->ApplyLinearImpulse(b2Vec2(0,5), myBody->GetWorldCenter(), true);
	myBody->SetGravityScale(0);
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
