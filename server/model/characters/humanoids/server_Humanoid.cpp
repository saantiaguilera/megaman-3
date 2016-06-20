/*
 * server_Humanoid.cpp
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#include "server_Humanoid.h"

#include <Collision/Shapes/b2CircleShape.h>
#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <Dynamics/b2Fixture.h>
#include <Dynamics/b2World.h>

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../../game_engine/server_Engine.h"
#include "../../../game_engine/server_EventContext.h"
#include "../../../serializers/server_EndGameSerializer.h"
#include "../../projectiles/server_Projectile.h"

Humanoid::Humanoid(unsigned int hp, float32 x, float32 y) :
		Character(hp) {
	b2BodyDef humanoidBodyDef;
	humanoidBodyDef.type = b2_dynamicBody;
	humanoidBodyDef.fixedRotation = true;
	humanoidBodyDef.position.Set(x, y);
//	std::cout << "Humanoid position instanced in " << x << "," << y << std::endl;
	// TODO: Maybe add it from the outside? when its created
	myBody = Engine::getInstance().getMyWorld()->CreateBody(&humanoidBodyDef);

	// Assign user data for callbacks
	myBody->SetUserData(this);

	// Add shape to body
	b2CircleShape circleShape;
	circleShape.m_radius = getWidth();
//	boxShape.SetAsBox(BODIES_SIZE,BODIES_SIZE);

	// Add fixture
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &circleShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);

	setFilteringGroup();
	addFootSensors();
}

Humanoid::~Humanoid() {
	Engine::getInstance().getMyWorld()->DestroyBody(getMyBody());
}

int Humanoid::getObjectType() {
	return OT_HUMANOID;
}

float32 Humanoid::getWidth() {
	return BODIES_SIZE;
}

float32 Humanoid::getHeight() {
	return BODIES_SIZE;
}

void Humanoid::handleCollisionWith(PhysicObject* objectCollidedWith) {
	if (objectCollidedWith->getObjectType() == OT_PROJECTILE) {
		Projectile* projectile = (Projectile*) objectCollidedWith;
		decreaseHp(projectile->getDamage());
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	}
}

void Humanoid::bossDestroyed() {
	EndGameSerializer* endGameSerializer = new EndGameSerializer();
	Engine::getInstance().getContext()->dispatchEvent(endGameSerializer);
	Engine::getInstance().setQuit(true);
}
