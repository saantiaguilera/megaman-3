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

MovementSerializer::MovementSerializer(unsigned int objectId, float x, float y) : PositionSerializer(objectId, x, y) {

}

MovementSerializer::~MovementSerializer() {
}

void MovementSerializer::serialize() {
	std::stringstream ss;
	messageCode = UPDATE_MOVEMENTS;
	ss << serializePosition();
	serialized = ss.str();
	messageLength = serialized.length();
}
