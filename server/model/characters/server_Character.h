/*
 * server_Character.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_
#define SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_

#include <cstddef>

#include "../../../common/common_Point.h"

class Projectile;

class Weapon;

class Character {
protected:
	// my current position
	Point myPoint;
	// hp are the hitpoints for current life
	unsigned int hp;
	// My weapon
	Weapon* currentWeapon;
public:
	// Constructor
	Character(unsigned int hp) : hp(hp), currentWeapon(NULL) {}
	// Destroyer
	virtual ~Character();
	// Moves the character
	void move(unsigned int x, unsigned int y);
	// Attacks
	void attack();
	// receive shot from weapon parameter
	virtual void receiveShotFromProjectile(Projectile* projectile);
	// Return hp of the character
	unsigned int getHp() const;
	// Decreases hp of the character
	void decreaseHp(unsigned int damage);

private:
	// Copy constructor
	Character(const Character&);
	// Assignment operator
	Character& operator=(const Character&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_ */
