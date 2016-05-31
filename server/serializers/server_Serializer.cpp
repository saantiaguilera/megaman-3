/*
 * server_Serializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_Serializer.h"

#include <sstream>

Serializer::Serializer() : objectId(0) {

}

Serializer::Serializer(unsigned int objectId) : objectId(objectId) {

}

Serializer::~Serializer() {
}

const std::string& Serializer::getSerialized() const {
	return serialized;
}

std::string Serializer::serializeObjectId() {
	std::stringstream ss;
	ss << objectId;
	return ss.str();
}
