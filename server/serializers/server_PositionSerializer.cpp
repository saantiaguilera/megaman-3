/*
 * server_MovementSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_PositionSerializer.h"

#include <sstream>

PositionSerializer::PositionSerializer(unsigned int objectId, int objectType, float x, float y) : Serializer(objectId, objectType), x(x), y(y) {
	serializePosition();
}

PositionSerializer::PositionSerializer(unsigned int objectId, float x, float y) : Serializer(objectId), x(x), y(y) {
	serializePosition();
}

PositionSerializer::~PositionSerializer() {
}

std::string PositionSerializer::serializePosition() {
	// { "id": ID, "type": TYPE, "position": { "x": 5, "y": 8 } }
	std::stringstream ss;
	ss << "{ \"id\": " << getObjectId() << ", \"type\": " << getObjectType() << "position\": { \"x\": " << x << ", \"y\": " << y << "} }";
	return ss.str();
}
