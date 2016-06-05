/*
 * server_ObjectDestructionSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_ObjectDestructionSerializer.h"

#include <sstream>
#include <string>

#include "../../common/common_MessageProtocol.h"

ObjectDestructionSerializer::ObjectDestructionSerializer(unsigned int objectId, float x, float y) : PositionSerializer(objectId, x, y) {
	messageCode = OBJECT_DESTROYED;
	serialize();
}

ObjectDestructionSerializer::~ObjectDestructionSerializer() {
}

void ObjectDestructionSerializer::serialize() {
	std::stringstream ss;
	ss << "{ \"id\": " << getObjectId() << "}";
	serialized = ss.str();
}
