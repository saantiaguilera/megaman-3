/*
 * server_Humanoid.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Humanoid.h"

#include <Collision/Shapes/b2PolygonShape.h>
#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <Dynamics/b2World.h>

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../../game_engine/server_Engine.h"
#include "../../projectiles/server_Projectile.h"


Humanoid::Humanoid(unsigned int hp, float32 x, float32 y) : Character(hp) {
	b2BodyDef humanoidBodyDef;
	humanoidBodyDef.type = b2_dynamicBody;
	humanoidBodyDef.fixedRotation = true;
	humanoidBodyDef.position.Set(x,y);
	// TODO: Maybe add it from the outside? when its created
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&humanoidBodyDef);

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
}


Humanoid::~Humanoid() {
	myBody->GetWorld()->DestroyBody(myBody);
}

int Humanoid::getObjectType() {
	return OT_HUMANOID;
}

void Humanoid::handleCollisionWith(PhysicObject* objectCollidedWith) {
	if(objectCollidedWith->getObjectType() == OT_PROJECTILE){
		Projectile* projectile = (Projectile*)objectCollidedWith;
		decreaseHp(projectile->getDamage());
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	}
}
