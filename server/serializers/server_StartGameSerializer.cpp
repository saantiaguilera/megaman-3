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

StartGameSerializer::StartGameSerializer(const std::string& mapNumber) {
	mapFileName = "level" + mapNumber + ".json";
	messageCode = START_GAME;
	serialize();
}

StartGameSerializer::~StartGameSerializer() {
}

void StartGameSerializer::serialize() {
	// TODO: Remove this hardcode here
	std::string fileroute = "./json/" + mapFileName;
	std::ifstream iFile(fileroute);
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
