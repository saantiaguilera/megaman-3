/*
 * server_Megaman.cpp
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#include "server_Megaman.h"

#include <Dynamics/b2Body.h>
#include <iostream>
#include <vector>

#include "../../../game_engine/physics/server_PhysicObject.h"
#include "../../../game_engine/server_Engine.h"
#include "../../projectiles/server_Projectile.h"
#include "../../weapons/server_PlasmaCannon.h"

Megaman::Megaman(float32 x, float32 y) : Humanoid(MEGAMAN_INITIAL_HP, x, y) {
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
		hp -= projectile->getDamage();
		Engine::getInstance().markObjectForRemoval(objectCollidedWith);
	}
}

void Megaman::update() {
	std::cout << "Megaman's position: " << myBody->GetPosition().x << "," << myBody->GetPosition().y << std::endl;
	std::cout << "Megaman's health: " << getHp() << std::endl;
}
