/*
 * server_NewPlayerSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_NewPlayerSerializer.h"

#include <sstream>

#include "../../common/common_MessageProtocol.h"

NewPlayerSerializer::NewPlayerSerializer(std::string playerName) : playerName(playerName){

}

NewPlayerSerializer::~NewPlayerSerializer() {
}

void NewPlayerSerializer::serialize() {
	// int uint float float
	std::stringstream ss;
	ss << NEW_PLAYER;
	ss << playerName;
	serialized = ss.str();
}
