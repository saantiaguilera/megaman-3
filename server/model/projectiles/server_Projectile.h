/*
 * server_Projectile.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_PROJECTILE_H_
#define SERVER_MODEL_PROJECTILES_SERVER_PROJECTILE_H_

#include <Common/b2Settings.h>

#include "../../game_engine/physics/server_PhysicObject.h"

class Projectile : public PhysicObject{
public:
	// Type of the projectile
	enum projectile_types_t { BOMB, FIRE, SPARK, MAGNET, PLASMA, RING } PROJECTILE_TYPE;
protected:
	// Damage to be inflicted
	unsigned int damage;
	// Initial x and y, need for them to be storaged because
	// box2d does not allow to create objects during time step
	float32 initialX, initialY;
	int facingPosition;

public:
	// Constructor
	Projectile( unsigned int damage, projectile_types_t type, float32 x, float32 y, ORIENTATION facingPosition);
	// Destroyer
	virtual ~Projectile();
	// Return projectile's damage
	unsigned int getDamage() const;
	// Return the projectiles type
	int getProjectileType() const;
	// Return object type
	virtual int getObjectType();
	// Get type for serialization
	virtual int getTypeForSerialization() = 0;
	// Set the projectiles body
	virtual void setBody();
	// Set user data for callbacks
	virtual void setUserData();
	virtual void update();

	virtual float32 getWidth();
	virtual float32 getHeight();

private:
	// Copy constructor
	Projectile(const Projectile&);
	// Assignment operator
	Projectile& operator=(const Projectile&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_PROJECTILE_H_ */
