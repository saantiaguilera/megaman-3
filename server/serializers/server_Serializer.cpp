/*
 * server_Serializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_Serializer.h"

#include <sstream>

Serializer::Serializer() : objectId(0), messageCode(0), messageLength(-1) {
}

Serializer::Serializer(unsigned int objectId) : objectId(objectId), messageCode(0), messageLength(-1) {

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

unsigned int Serializer::getObjectId() const {
	return objectId;
}

int Serializer::getMessageCode() const {
	return messageCode;
}

int Serializer::getMessageLength() const {
	return messageLength;
}
