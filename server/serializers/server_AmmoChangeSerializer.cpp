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

AmmoChangeSerializer::AmmoChangeSerializer(Weapon* weapon) : Serializer(0), newAmmo(weapon->getAmmo()), weapon(weapon) {
	messageCode = AMMO_CHANGE;
	serialize();
}

AmmoChangeSerializer::~AmmoChangeSerializer() {
}

void AmmoChangeSerializer::serialize() {
	std::stringstream ss;
	ss << "{" << "\"ammo\": " << newAmmo << ", \"special\": " << std::boolalpha << weapon->isSpecial() << "}";
	serialized = ss.str();
}
