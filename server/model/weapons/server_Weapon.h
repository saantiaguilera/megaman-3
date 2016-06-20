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

#include "../characters/server_Character.h"
#include "../../game_engine/physics/server_PhysicObject.h"

enum WeaponTypes { PLASMA_CANNON = 28, BOMB_CANNON = 23, FLAMETHROWER = 24, MAGNET_CANNON = 25, RING_TOSSER = 26, SPARKS_CANNON = 27 };

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
	virtual void fire(float32 x, float32 y, PhysicObject::ORIENTATION facingPosition) = 0;
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
