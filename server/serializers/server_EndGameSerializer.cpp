/*
 * server_EndGameSerializer.cpp
 *
 *  Created on: May 31, 2016
 *      Author: mastanca
 */

#include "server_EndGameSerializer.h"

#include <string>

#include "../../common/common_MessageProtocol.h"

EndGameSerializer::EndGameSerializer() {
	messageCode = END_GAME;
	serialize();
}

EndGameSerializer::~EndGameSerializer() {
}

void EndGameSerializer::serialize() {
	serialized = " ";
}
