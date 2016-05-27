/*
 * server_Character.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_
#define SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_

#include "../server_Movable.h"
#include "../server_PhysicObject.h"

class Projectile;

class Weapon;


class Character : public Movable, public PhysicObject{
protected:
	// hp are the hitpoints for current life
	unsigned int hp;
	// My weapon
	Weapon* currentWeapon;
	// Prepare to attack, if true then attack
	bool readyToAttack;
	// clock ticks counter
	unsigned int ticksPassed;
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
	void decreaseHp(float damage);
	// Update the AI (make it pure virtual later)
	virtual void update() {}

private:
	// Copy constructor
	Character(const Character&);
	// Assignment operator
	Character& operator=(const Character&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_ */
