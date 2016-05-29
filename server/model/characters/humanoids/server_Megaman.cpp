/*
 * server_Megaman.cpp
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#include "server_Megaman.h"

#include <Dynamics/b2Body.h>
#include <iostream>
#include <string>

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../../game_engine/server_Engine.h"
#include "../../../game_engine/server_Player.h"
#include "../../../server_Logger.h"
#include "../../obstacles/server_Obstacle.h"
#include "../../powerups/server_Powerup.h"
#include "../../projectiles/server_Projectile.h"
#include "../../weapons/server_PlasmaCannon.h"

Megaman::Megaman(Player* humanOperator, float32 x, float32 y) : Humanoid(MEGAMAN_INITIAL_HP, x, y), humanOperator(humanOperator) {
	currentWeapon = new PlasmaCannon();
}

Megaman::~Megaman() {
}

int Megaman::getObjectType() {
	return OT_MEGAMAN;
}

void Megaman::handleCollisionWith(PhysicObject* objectCollidedWith) {
	if(objectCollidedWith->getObjectType() == OT_PROJECTILE){
		Projectile* projectile = (Projectile*)objectCollidedWith;
		decreaseHp(projectile->getDamage());
	    Logger::getInstance().log(1, getHumanOperator()->getName() + " received shot, new hp is " + getHpAsString());
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	} else if (objectCollidedWith->getObjectType() == OT_POWERUP) {
		Powerup* powerup = (Powerup*)objectCollidedWith;
	    Logger::getInstance().log(1, getHumanOperator()->getName() + " picked a powerup");
		powerup->haveEffectOn(this);
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	} else if (objectCollidedWith->getObjectType() == OT_OBSTACLE) {
		Obstacle* obstacle = (Obstacle*)objectCollidedWith;
		obstacle->haveEffectOn(this);
	}
}

Player* Megaman::getHumanOperator() const {
	return humanOperator;
}

void Megaman::update() {
	std::cout << "Megaman's position: " << myBody->GetPosition().x << "," << myBody->GetPosition().y << std::endl;
	std::cout << "Megaman's health: " << getHp() << std::endl;
}
