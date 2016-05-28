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
}

Projectile::Projectile(unsigned int damage, projectile_types_t type) {
	PROJECTILE_TYPE = type;
	this->damage = damage;

	b2BodyDef projectileBodyDef;
	projectileBodyDef.type = b2_kinematicBody;
	// TODO: send x and y positions in constructor
	projectileBodyDef.position.Set(0,0);
	// TODO: Maybe add it from the outside? when its created
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&projectileBodyDef);

	// Add shape to body
	// TODO: remove hardcoded parameters
	b2PolygonShape boxShape;
	boxShape.SetAsBox(1,1);

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);

	// Apply an impulse <-- this directio
	myBody->ApplyLinearImpulse(b2Vec2(-5,0), myBody->GetWorldCenter(), true);
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
