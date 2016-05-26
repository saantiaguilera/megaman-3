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
	b2Body* myBody;
public:
	// Constructor
	PhysicObject();
	// Destroyer
	virtual ~PhysicObject();
private:
	// Copy constructor
	PhysicObject(const PhysicObject&);
	// Assignment operator
	PhysicObject& operator=(const PhysicObject&);
};

#endif /* SERVER_MODEL_SERVER_PHYSICOBJECT_H_ */
