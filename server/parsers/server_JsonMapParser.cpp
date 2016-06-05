/*
 * server_JsonMapParser.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: mastanca
 */

#include "server_JsonMapParser.h"

#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>

#include "../../common/common_MapConstants.h"
#include "../../common/common_MapViewParser.h"
#include "../model/obstacles/server_Block.h"
#include "../model/obstacles/server_BossChamberGate.h"
#include "../model/obstacles/server_Ladder.h"
#include "../model/obstacles/server_Needle.h"
#include "../model/obstacles/server_Precipice.h"


JsonMapParser::JsonMapParser() {
}

JsonMapParser::~JsonMapParser() {
}

void JsonMapParser::parseDocument(const std::string& name) {
	MapViewParser mapParser;
	rapidjson::Document* document = mapParser.serverMapFromPath(name);
	const rapidjson::Value& mapJson = (*document)[MAP_NAME];

	const rapidjson::Value& obstaclesJson = mapJson[OBSTACLES_NAME];

	for (rapidjson::SizeType i = 0; i < obstaclesJson.Size(); i++) {
		unsigned int x = obstaclesJson[i][X_NAME].GetInt();
		unsigned int y = obstaclesJson[i][Y_NAME].GetInt();
		int type = obstaclesJson[i][TYPE_NAME].GetInt();

		switch (type) {
			case ObstacleViewTypeBlock:
				new Block(x, y);
				break;
			case ObstacleViewTypeBossChamberGate:
				new BossChamberGate(x, y);
				break;
			case ObstacleViewTypeLadder:
				new Ladder(x, y);
				break;
			case ObstacleViewTypeNeedle:
				new Needle(x, y);
				break;
			case ObstacleViewTypePrecipice:
				new Precipice(x, y);
				break;
			default:
				break;
		}


	}
}
