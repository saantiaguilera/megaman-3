/*
 * server_PhysicObject.h
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_SERVER_PHYSICOBJECT_H_
#define SERVER_MODEL_SERVER_PHYSICOBJECT_H_
class b2Body;

class PhysicObject {
protected:
	enum _moveState {
	MS_STOP,
	MS_LEFT,
	MS_RIGHT,
	MS_JUMP
	};
	// Id of the object
	static unsigned int id;
	// box2d body
	b2Body* myBody;
public:
	// Constructor
	PhysicObject();
	// Destroyer
	virtual ~PhysicObject();
	// Return object id
	unsigned int getId() const;
	// Move
	void move(unsigned int moveState);
private:
	// Copy constructor
	PhysicObject(const PhysicObject&);
	// Assignment operator
	PhysicObject& operator=(const PhysicObject&);
};

#endif /* SERVER_MODEL_SERVER_PHYSICOBJECT_H_ */
