/*
 * server_Serializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "common_Serializer.h"

#include <iostream>

Serializer::Serializer() : objectId(0), messageCode(0), serialized("") {
}

Serializer::Serializer(unsigned int objectId) : objectId(objectId), messageCode(0) {

}

Serializer::~Serializer() {
}

std::string Serializer::getSerialized() {
	return serialized;
}

unsigned int Serializer::getObjectId() const {
	return objectId;
}

int Serializer::getMessageCode() const {
	return messageCode;
}

int Serializer::getMessageLength() const {
	return serialized.length();
}
