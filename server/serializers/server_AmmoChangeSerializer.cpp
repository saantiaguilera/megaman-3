/*
 * server_AmmoChangeSerializer.cpp
 *
 *  Created on: May 31, 2016
 *      Author: mastanca
 */

#include "server_AmmoChangeSerializer.h"

#include <sstream>
#include <string>

#include "../../common/common_MessageProtocol.h"

AmmoChangeSerializer::AmmoChangeSerializer(unsigned int newAmmo, unsigned int objectId) : Serializer(objectId), newAmmo(newAmmo) {
	messageCode = AMMO_CHANGE;
	serialize();
}

AmmoChangeSerializer::~AmmoChangeSerializer() {
}

void AmmoChangeSerializer::serialize() {
	std::stringstream ss;
	ss << "{" << "\"ammo\": " << newAmmo << "," << "\"id\": " << objectId << "}";
	serialized = ss.str();
}
