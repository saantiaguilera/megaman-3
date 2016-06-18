/*
 * server_Megaman.h
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_MEGAMAN_H_
#define SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_MEGAMAN_H_

#include <Common/b2Settings.h>

#include "../../weapons/server_Weapon.h"
#include "server_Humanoid.h"
#include <map>

class Player;

#define MEGAMAN_INITIAL_HP 150

class Megaman : public Humanoid {
private:
	Player* humanOperator = NULL;
	std::map<int, Weapon*> availableWeaponsMap;
public:
	// Constructor
	Megaman(Player* humanOperator, float32 x, float32 y);
	// Destroyer
	virtual ~Megaman();
	// Return object type
	virtual int getObjectType();
	// Handle collisions
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith);
	// Handle stop collisions
	virtual void handleStopCollidingWith(PhysicObject* objectCollidedWith);
	// Update object (AI)
	// TODO: For testing collisions
	virtual void update();
	// Return my operator
	Player* getHumanOperator() const;
	virtual void receiveShotFromProjectile(Projectile *projectile);
	virtual void attack();
	virtual void increaseHP(unsigned int amount);
	virtual bool isAI();
	unsigned int getBoundId();
	// Switch weapon to the chosen one
	// If its not available then no change is done
	void changeWeaponTo(int weaponType);
	// Make a weapon available by setting a reference in the weapons map
	void makeWeaponAvailable(int weaponType, Weapon* newWeapon);
	// Decreases hp of megaman and eventually its operators lives
	virtual void decreaseHp(float damage);
	// Get type for serialization
	virtual int getTypeForSerialization();

private:
	// Copy constructor
	Megaman(const Megaman&);
	// Assignment operator
	Megaman& operator=(const Megaman&);
};

#endif /* SERVER_MODEL_CHARACTERS_HUMANOIDS_SERVER_MEGAMAN_H_ */
