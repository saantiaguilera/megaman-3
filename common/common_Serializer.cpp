/*
 * server_Serializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "common_Serializer.h"

#include <iostream>

Serializer::Serializer() : objectId(0), messageCode(0), objectType(), serialized("") {
}

Serializer::Serializer(unsigned int objectId, int objectType) : objectId(objectId), messageCode(0), objectType(objectType) {

}

Serializer::Serializer(unsigned int objectId) : objectId(objectId), messageCode(0), objectType(0) {

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

int Serializer::getObjectType() {
	return objectType;
}

int Serializer::getMessageLength() const {
	return serialized.length();
}

void Serializer::setDispatchAll() {
	this->dispatchAll = true;
}

void Serializer::setDispatchClient(unsigned int clientID) {
	this->dispatchAll = false;
	this->dispatchClientID = clientID;
}
// Get if event is dispatched to all clients
bool Serializer::getDispatchAll() {
	return this->dispatchAll;
}
// Get the clientID that has to be dispatched the event to
unsigned int Serializer::getDispatchClientID() {
	return this->dispatchClientID;
}
