/*
 * server_Projectile.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_PROJECTILE_H_
#define SERVER_MODEL_PROJECTILES_SERVER_PROJECTILE_H_

class Projectile {
public:
	// Type of the projectile
	enum projectile_types_t { BOMB, FIRE, SPARK, MAGNET, PLASMA, RING } PROJECTILE_TYPE;
protected:
	// Damage to be inflicted
	unsigned int damage;
public:
	// Constructor
	Projectile( unsigned int damage, projectile_types_t type);
	// Destroyer
	virtual ~Projectile();
	// Return projectile's damage
	unsigned int getDamage() const;
	// Return the projectiles type
	int getProjectileType() const;

private:
	// Copy constructor
	Projectile(const Projectile&);
	// Assignment operator
	Projectile& operator=(const Projectile&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_PROJECTILE_H_ */
