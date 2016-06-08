/*
 * server_ObjectCreationSerializer.h
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_OBJECTCREATIONSERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_OBJECTCREATIONSERIALIZER_H_

#include "server_PositionSerializer.h"
#include "../game_engine/physics/server_PhysicObject.h"

class ObjectCreationSerializer: public PositionSerializer {
public:
	// Constructor
	ObjectCreationSerializer(PhysicObject* object);
	// Destroyer
	virtual ~ObjectCreationSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	ObjectCreationSerializer(const ObjectCreationSerializer&);
	// Assignment operator
	ObjectCreationSerializer& operator=(const ObjectCreationSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_OBJECTCREATIONSERIALIZER_H_ */
