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

LifeChangeSerializer::LifeChangeSerializer(unsigned int newLifeCount) : newLifeCount(newLifeCount) {
	messageCode = LIFE_CHANGE;
	serialize();
}

LifeChangeSerializer::~LifeChangeSerializer() {
}

void LifeChangeSerializer::serialize() {
	std::stringstream ss;
	ss << "{" << "\"life\": " << newLifeCount << "}";
	serialized = ss.str();
}
