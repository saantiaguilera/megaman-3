/*
 * server_AmmoChangeSerializer.cpp
 *
 *  Created on: May 31, 2016
 *      Author: mastanca
 */

#include "server_AmmoChangeSerializer.h"

#include <iostream>
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
	unsigned int ammoPercentage = (newAmmo * 100) / weapon->getMaxAmmo();

	std::stringstream ss;
	ss << "{" << "\"ammo\": " << ammoPercentage << ", \"special\": " << std::boolalpha << weapon->isSpecial() << "}";
	serialized = ss.str();
	std::cout << serialized << std::endl;
}
