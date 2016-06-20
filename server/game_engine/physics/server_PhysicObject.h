/*
 * server_PhysicObject.h
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_PHYSICS_SERVER_PHYSICOBJECT_H_
#define SERVER_GAME_ENGINE_PHYSICS_SERVER_PHYSICOBJECT_H_

#include <Common/b2Math.h>
#include "../../../common/common_MapConstants.h"
#include <Dynamics/b2Body.h>

// 0.001852
//const float BODIES_SIZE = (TERRAIN_TILE_SIZE / (float) METERS_TO_PIXELS_RATIO) - 0.004;
const float BODIES_SIZE = TERRAIN_TILE_SIZE*METERS_TO_PIXELS_RATIO/2;

//const float STEP_LENGTH = TERRAIN_TILE_SIZE/METERS_TO_PIXELS_RATIO;
const float STEP_LENGTH = 3.5f;

#define TICKS_TILL_VULNERABLE_DEFAULT 20

class PhysicObject {
protected:
	// Object types for collision detection
	enum _objectTypes {
		OT_HUMANOID,
		OT_MEGAMAN,
		OT_MOB,
		OT_POWERUP,
		OT_PROJECTILE,
		OT_OBSTACLE,
		OT_LADDER,
		OT_RING
	};
	// Global count of the objects
	static unsigned int globalCount;
	// Id of the object
	unsigned int id;
	// box2d body
	b2Body* myBody;
	// number of foot contacts (to avoid air jumping)
	long numFootContacts;
	// notify creation of the object
	void notify();
	// Determine if i am updatable
	bool updatable;

	virtual float32 getWidth() = 0;
	virtual float32 getHeight() = 0;
	bool vulnerable;
	unsigned int ticksTillVulnerable;
public:
	// Defined movestates for objects
	enum _moveState {
		MS_LEFT,
		MS_RIGHT,
		MS_DOWN,
		MS_JUMP,
		MS_STOP
		};
	enum ORIENTATION {
		OR_LEFT,
		OR_RIGHT,
		OR_BOTTOM,
		OR_TOP
	};
	// Constructor
	PhysicObject();
	// Destroyer
	virtual ~PhysicObject();
	// Return object id
	unsigned int getId() const;
	// Move
	void move(unsigned int moveState);
	// Get type of object
	virtual int getObjectType() = 0;
	// Get type for serialization
	virtual int getTypeForSerialization() = 0;
	// Handle collisions
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith);
	// Handle collision stop
	virtual void handleStopCollidingWith(PhysicObject* objectCollidedWith);
	// Return my body
	b2Body* getMyBody() const;
	// Return my x position
	float getPositionX() const;
	// Return my y position
	float getPositionY() const;
	// Facing position
	ORIENTATION facingPosition;
	// The following methods are needed to create projectiles in runtime
	// Set my body
	virtual void setBody();
	// Set user data for callbacks
	virtual void setUserData();
	// For AI and bullet movements
	virtual void update();
	bool isUpdatable() const;
	void setUpdatable(bool updatable);
	bool isVulnerable() const;
	void setVulnerable(bool vulnerable);

	virtual void incFootContacts() {};
	virtual void decFootContacts() {};

private:
	// Copy constructor
	PhysicObject(const PhysicObject&);
	// Assignment operator
	PhysicObject& operator=(const PhysicObject&);
};

#endif /* SERVER_GAME_ENGINE_PHYSICS_SERVER_PHYSICOBJECT_H_ */
