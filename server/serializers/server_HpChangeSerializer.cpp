/*
 * server_HpChangeSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_HpChangeSerializer.h"

#include <sstream>
#include <string>

#include "../../common/common_MessageProtocol.h"

HpChangeSerializer::HpChangeSerializer(unsigned int newHp, unsigned int objectId) : Serializer(objectId), newHp(newHp) {

}

HpChangeSerializer::~HpChangeSerializer() {
}

void HpChangeSerializer::serialize() {
	// int uint uint
	std::stringstream ss;
	ss << HP_CHANGE;
	ss << serializeObjectId();
	ss << newHp;
	serialized = ss.str();
}
