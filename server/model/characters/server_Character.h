/*
 * server_Character.h
 *
 *  Created on: May 13, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_
#define SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_

#include "../weapons/server_Weapon.h"
#include <cstddef>

class Character {
protected:
	// hp are the hitpoints for current life
	unsigned int hp;
	Weapon* currentWeapon;
public:
	// Constructor
	Character(unsigned int hp) : hp(hp), currentWeapon(NULL) {}
	// Destroyer
	virtual ~Character();
	// Moves the character
	virtual void move() = 0;
	// Attacks
	virtual void attack() = 0;
	// receive shot from weapon parameter
	void receiveShotFromWeapon(Weapon* weapon);
private:
	// Copy constructor
	Character(const Character&);
	// Assignment operator
	Character& operator=(const Character&);
};

#endif /* SERVER_MODEL_CHARACTERS_SERVER_CHARACTER_H_ */
