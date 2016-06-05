/*
 * server_Character.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_
#define SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_

#include <string>

#include "../../game_engine/physics/server_PhysicObject.h"

class Projectile;

class Weapon;

class Character: public PhysicObject {
protected:
	// hp are the hitpoints for current life
	unsigned int hp;
	// My weapon
	Weapon* currentWeapon;
	// Prepare to attack, if true then attack
	bool readyToAttack;
	// clock ticks counter
	unsigned int ticksPassed;
	// Change my weapon for anotherWeapon
	void setCurrentWeapon(Weapon* anotherWeapon);
	// Get type for serialization
	virtual int getTypeForSerialization() = 0;
public:
	// Constructor
	Character(unsigned int hp);
	// Destroyer
	virtual ~Character();
	// Attacks
	void attack();
	// receive shot from weapon parameter
	virtual void receiveShotFromProjectile(Projectile* projectile);
	// Return hp of the character
	unsigned int getHp() const;
	// Decreases hp of the character
	virtual void decreaseHp(float damage);
	// Increase the hp of the character by amount
	void increaseHP(unsigned int amount);
	// Update the AI (make it pure virtual later)
	virtual void update() {};
	// Return my current weapon
	Weapon* getCurrentWeapon() const;
	// Return my hp as a string
	std::string getHpAsString();

private:
	// Copy constructor
	Character(const Character&);
	// Assignment operator
	Character& operator=(const Character&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_ */
