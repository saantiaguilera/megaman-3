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
	// Damage inflicted by the weapon
	// Ammo of the weapon
	unsigned int damage, ammo;
public:
	// Constructor
	Weapon(unsigned int damage, unsigned int ammo) :
			damage(damage), ammo(ammo) {
	}
	// Destroyer
	virtual ~Weapon();
	// Fire weapon inflicting damage and reducing ammo
	void fire(Character* character);
	unsigned int getDamage() const;

private:
	// Copy constructor
	Weapon(const Weapon&);
	// Assignment operator
	Weapon& operator=(const Weapon&);
};

#endif /* SERVER_MODEL_WEAPONS_SERVER_WEAPON_H_ */
