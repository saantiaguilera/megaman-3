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

HpChangeSerializer::HpChangeSerializer(unsigned int newHp, Character* character) : Serializer(character->getId()), newHp(newHp), character(character) {
	messageCode = HP_CHANGE;
	serialize();
}

HpChangeSerializer::~HpChangeSerializer() {
}

void HpChangeSerializer::serialize() {
	std::stringstream ss;
	unsigned int hpPercentage = (newHp*100)/(character->getMaxHp());
	ss << "{" << "\"hp\": " << hpPercentage << "," << "\"id\": " << objectId << "}";
	serialized = ss.str();
}
