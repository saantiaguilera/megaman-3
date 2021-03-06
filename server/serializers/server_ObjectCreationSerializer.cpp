/*
 * server_ObjectCreationSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_ObjectCreationSerializer.h"

#include <sstream>
#include <string>

#include "../../common/common_MessageProtocol.h"

ObjectCreationSerializer::ObjectCreationSerializer(PhysicObject* object) : PositionSerializer(object->getId(), object->getTypeForSerialization(), object->getPositionX(), object->getPositionY()) {
	messageCode = OBJECT_CREATED;
	serialize();
}

ObjectCreationSerializer::~ObjectCreationSerializer() {
}

void ObjectCreationSerializer::serialize() {
	// { "id": ID, "type": TYPE, "position": { "x": 5, "y": 8 } }
	std::stringstream ss;
	ss << serializePosition();
	serialized = ss.str();
}
