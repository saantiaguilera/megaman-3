/*
 * server_PhysicObject.h
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_PHYSICS_SERVER_PHYSICOBJECT_H_
#define SERVER_GAME_ENGINE_PHYSICS_SERVER_PHYSICOBJECT_H_

#include "../../../common/common_MapConstants.h"
class b2Body;

#define BODIES_SIZE 70

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
		OT_LADDER
	};
	// Id of the object
	static unsigned int id;
	// box2d body
	b2Body* myBody;
	// number of foot contacts (to avoid air jumping)
	unsigned int numFootContacts;
	// notify creation of the object
	void notify();
public:
	// Defined movestates for objects
	enum _moveState {
		MS_LEFT,
		MS_RIGHT,
		MS_DOWN,
		MS_JUMP,
		MS_STOP
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
	enum _facingSide {
		OT_RIGHT = 5,
		OT_LEFT = -5
	};
	int facingPosition;
	// Set my body
	virtual void setBody();

private:
	// Copy constructor
	PhysicObject(const PhysicObject&);
	// Assignment operator
	PhysicObject& operator=(const PhysicObject&);
};

#endif /* SERVER_GAME_ENGINE_PHYSICS_SERVER_PHYSICOBJECT_H_ */
