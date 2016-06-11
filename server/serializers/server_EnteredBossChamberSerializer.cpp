/*
 * server_EnteredBossChamberSerializer.cpp
 *
 *  Created on: Jun 6, 2016
 *      Author: mastanca
 */

#include "server_EnteredBossChamberSerializer.h"

#include <sstream>
#include <string>
#include <fstream>

#include "../../common/common_MessageProtocol.h"
#include "../game_engine/server_Engine.h"


EnteredBossChamberSerializer::EnteredBossChamberSerializer() {
	messageCode = ENTERED_BOSS_CHAMBER;
	serialize();
}

EnteredBossChamberSerializer::~EnteredBossChamberSerializer() {
}

void EnteredBossChamberSerializer::serialize() {
	std::stringstream mapIdstring;
	mapIdstring << Engine::getInstance().getCurrentMapId();
	std::string filename = "bosschamber" + mapIdstring.str() + ".json";
	std::string fileroute = "./json/" + filename;
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
