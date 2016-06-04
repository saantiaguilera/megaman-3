/*
 * server_NewPlayerSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_NewPlayerSerializer.h"

#include <iostream>
#include <sstream>

#include "../../common/common_MessageProtocol.h"

NewPlayerSerializer::NewPlayerSerializer(std::string playerName) : playerName(playerName){
	messageCode = NEW_PLAYER;
	serialize();
}

NewPlayerSerializer::~NewPlayerSerializer() {
}

void NewPlayerSerializer::serialize() {
	std::stringstream ss;
	ss << playerName;
	serialized = ss.str();
}
