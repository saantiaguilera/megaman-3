/*
 * server_StartGameSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_StartGameSerializer.h"

#include <sstream>
#include <string>

#include "../../common/common_MessageProtocol.h"

StartGameSerializer::StartGameSerializer() {

}

StartGameSerializer::~StartGameSerializer() {
}

void StartGameSerializer::serialize() {
	messageCode = START_GAME;
	serialized = "";
	messageLength = 0;
}
