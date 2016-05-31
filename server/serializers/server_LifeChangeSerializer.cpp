/*
 * server_LifeChangeSerializer.cpp
 *
 *  Created on: May 31, 2016
 *      Author: mastanca
 */

#include "server_LifeChangeSerializer.h"

#include <sstream>
#include <string>

#include "../../common/common_MessageProtocol.h"

LifeChangeSerializer::LifeChangeSerializer(unsigned int playerId) : Serializer(playerId) {

}

LifeChangeSerializer::~LifeChangeSerializer() {
}

void LifeChangeSerializer::serialize() {
	// int uint float float
	std::stringstream ss;
	ss << LIFE_CHANGE;
	ss << serializeObjectId();
	serialized = ss.str();
}
