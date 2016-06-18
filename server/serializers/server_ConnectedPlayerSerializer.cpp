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
#include "../networking/server_ClientProxy.h"

ConnectedPlayerSerializer::ConnectedPlayerSerializer(ClientProxy* clientProxy) : clientProxy(clientProxy) {
	messageCode = CONNECTED_PLAYER_ID;
	serialize();
}

ConnectedPlayerSerializer::~ConnectedPlayerSerializer() {
}

void ConnectedPlayerSerializer::serialize() {
	std::stringstream ss;
	ss << "{" << "\"your_id\": " << clientProxy->getId() << "}";
	serialized = ss.str();
}

