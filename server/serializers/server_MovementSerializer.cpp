/*
 * server_MovementSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_MovementSerializer.h"

#include <sstream>
#include <string>

#include "../../common/common_MessageProtocol.h"

MovementSerializer::MovementSerializer(unsigned int  objectId, float x, float y) : PositionSerializer(objectId, x, y) {
	messageCode = UPDATE_MOVEMENTS;
	serialize();
}

MovementSerializer::~MovementSerializer() {
}

void MovementSerializer::serialize() {
	std::stringstream ss;
	ss << serializePosition();
	serialized = ss.str();
}
