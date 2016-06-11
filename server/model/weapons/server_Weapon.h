/*
 * server_Weapon.h
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_WEAPONS_SERVER_WEAPON_H_
#define SERVER_MODEL_WEAPONS_SERVER_WEAPON_H_

#include <Common/b2Settings.h>

#define BULLET_X_OFFSET 5

class Character;

enum WeaponTypes { PLASMA_CANNON, BOMB_CANNON, FLAMETHROWER, MAGNET_CANNON, RING_TOSSER, SPARKS_CANNON };

class Weapon {
protected:
	// Ammo of the weapon
	unsigned int ammo;
public:
	// Constructor
	Weapon(unsigned int ammo);
	// Destroyer
	virtual ~Weapon();
	// Fire weapon reducing ammo, passes current position for creating projectile
	virtual void fire(float32 x, float32 y, int facingPosition) = 0;
	// Increase ammo by the amount given
	void increaseAmmoBy(unsigned int ammoAmount);
	// Return current ammo
	unsigned int getAmmo() const;
	// Tell if the weapon is a special one
	virtual bool isSpecial();
	// Return max ammo of the weapon
	virtual unsigned int getMaxAmmo() = 0;

private:
	// Copy constructor
	Weapon(const Weapon&);
	// Assignment operator
	Weapon& operator=(const Weapon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_WEAPON_H_ */
