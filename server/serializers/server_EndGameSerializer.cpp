/*
 * server_EndGameSerializer.cpp
 *
 *  Created on: May 31, 2016
 *      Author: mastanca
 */

#include "server_EndGameSerializer.h"

#include <sstream>
#include <string>

#include "../../common/common_MessageProtocol.h"

EndGameSerializer::EndGameSerializer() {

}

EndGameSerializer::~EndGameSerializer() {
}

void EndGameSerializer::serialize() {
	// int uint float float
	std::stringstream ss;
	ss << END_GAME;
	serialized = ss.str();
}
