/*
 * server_ConnectedPlayerSerializer.cpp
 *
 *  Created on: Jun 17, 2016
 *      Author: mastanca
 */

#include "server_ConnectedPlayerSerializer.h"

#include <sstream>
#include <string>

#include "../../common/common_MessageProtocol.h"
#include "../model/characters/humanoids/server_Megaman.h"

ConnectedPlayerSerializer::ConnectedPlayerSerializer(Megaman* megaman) : megaman(megaman) {
	messageCode = CONNECTED_PLAYER_ID;
	serialize();
}

ConnectedPlayerSerializer::~ConnectedPlayerSerializer() {
}

void ConnectedPlayerSerializer::serialize() {
	std::stringstream ss;
	ss << "{" << "\"your_id\": " << megaman->getId() << "}";
	serialized = ss.str();
}

