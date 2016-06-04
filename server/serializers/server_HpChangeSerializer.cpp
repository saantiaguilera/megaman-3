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
	std::stringstream ss;
	messageCode = HP_CHANGE;
	ss << "{" << "\"hp\": " << newHp << "," << "\"id\": " << objectId << "}";
	serialized = ss.str();
}
