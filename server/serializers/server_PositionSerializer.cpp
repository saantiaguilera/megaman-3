/*
 * server_MovementSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_PositionSerializer.h"

#include <sstream>

PositionSerializer::PositionSerializer(unsigned int objectId, float x, float y) : Serializer(objectId), x(x), y(y) {
	serializePosition();
}

PositionSerializer::~PositionSerializer() {
}

std::string PositionSerializer::serializePosition() {
	std::stringstream ss;
	ss << "{ \"id\": " << getObjectId() << ", \"position\": { \"x\": " << x << ", \"y\": " << y << "} }";
	return ss.str();
}
