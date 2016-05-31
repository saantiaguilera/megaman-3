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

}

AmmoChangeSerializer::~AmmoChangeSerializer() {
}

void AmmoChangeSerializer::serialize() {
	// int uint uint
	std::stringstream ss;
	ss << AMMO_CHANGE;
	ss << serializeObjectId();
	ss << newAmmo;
	serialized = ss.str();
}
