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

}

ObjectDestructionSerializer::~ObjectDestructionSerializer() {
}

void ObjectDestructionSerializer::serialize() {
	// int uint float float
	std::stringstream ss;
	ss << OBJECT_DESTROYED;
	ss << serializeObjectId();
	ss << serializePosition();
	serialized = ss.str();
}