/*
 * server_Weapon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_WEAPON_H_
#define SERVER_MODEL_WEAPONS_SERVER_WEAPON_H_
class Character;

class Weapon {
protected:
	// Ammo of the weapon
	unsigned int ammo;
public:
	// Constructor
	Weapon(unsigned int ammo);
	// Destroyer
	virtual ~Weapon();
	// Fire weapon reducing ammo
	virtual void fire() = 0;

private:
	// Copy constructor
	Weapon(const Weapon&);
	// Assignment operator
	Weapon& operator=(const Weapon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_WEAPON_H_ */
