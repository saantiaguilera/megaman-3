/*
 * server_StartGameSerializer.cpp
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#include "server_StartGameSerializer.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "../../common/common_MessageProtocol.h"

StartGameSerializer::StartGameSerializer() {
	messageCode = START_GAME;
	serialize();
}

StartGameSerializer::~StartGameSerializer() {
}

void StartGameSerializer::serialize() {
	std::ifstream iFile("/home/mastanca/workspace/fiuba-taller-I-megaman/json/level1.json");
	std::stringstream ss;
	if (!iFile)
		return;
	while (true) {
	    std::string line;
	    std::getline(iFile, line);
	    if( iFile.eof() ) break;
	    ss << line;
	}
	serialized = ss.str();
}
