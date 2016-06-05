/*
 * server_ObjectDestructionSerializer.h
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_OBJECTDESTRUCTIONSERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_OBJECTDESTRUCTIONSERIALIZER_H_

#include "server_PositionSerializer.h"

class ObjectDestructionSerializer: public PositionSerializer {
public:
	// Constructor
	ObjectDestructionSerializer(unsigned int objectId, float x, float y);
	// Destroyer
	virtual ~ObjectDestructionSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	ObjectDestructionSerializer(const ObjectDestructionSerializer&);
	// Assignment operator
	ObjectDestructionSerializer& operator=(const ObjectDestructionSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_OBJECTDESTRUCTIONSERIALIZER_H_ */
