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

ObjectCreationSerializer::ObjectCreationSerializer(unsigned int objectId, float x, float y) : PositionSerializer(objectId, x, y) {

}

ObjectCreationSerializer::~ObjectCreationSerializer() {
}

void ObjectCreationSerializer::serialize() {
	std::stringstream ss;
	messageCode = OBJECT_CREATED;
	ss << serializePosition();
	serialized = ss.str();
}
