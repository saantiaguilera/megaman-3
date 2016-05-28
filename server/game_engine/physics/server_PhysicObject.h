/*
 * server_PhysicObject.h
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_PHYSICS_SERVER_PHYSICOBJECT_H_
#define SERVER_GAME_ENGINE_PHYSICS_SERVER_PHYSICOBJECT_H_
class b2Body;

class PhysicObject {
protected:
	// Defined movestates for objects
	enum _moveState {
		MS_STOP,
		MS_LEFT,
		MS_RIGHT,
		MS_JUMP
		};
	// Object types for collission detection
	enum _objectTypes {
		OT_HUMANOID,
		OT_MEGAMAN,
		OT_MOB,
		OT_POWERUP,
		OT_OBSTACLE,
		OT_PROJECTILE
	};
	// Id of the object
	static unsigned int id;
	// box2d body
	b2Body* myBody;
	// number of foot contacts (to avoid air jumping)
	unsigned int numFootContacts;
public:
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
	// Handle collisions
	virtual void handleCollisionWith(PhysicObject* objectCollidedWith);
private:
	// Copy constructor
	PhysicObject(const PhysicObject&);
	// Assignment operator
	PhysicObject& operator=(const PhysicObject&);
};

#endif /* SERVER_GAME_ENGINE_PHYSICS_SERVER_PHYSICOBJECT_H_ */
