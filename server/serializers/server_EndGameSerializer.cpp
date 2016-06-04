/*
 * server_EndGameSerializer.cpp
 *
 *  Created on: May 31, 2016
 *      Author: mastanca
 */

#include "server_EndGameSerializer.h"

#include "../../common/common_MessageProtocol.h"

EndGameSerializer::EndGameSerializer() {

}

EndGameSerializer::~EndGameSerializer() {
}

void EndGameSerializer::serialize() {
	messageCode = END_GAME;
	messageLength = 0;
	serialized = "";
}
