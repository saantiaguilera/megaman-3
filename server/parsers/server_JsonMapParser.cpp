/*
 * server_JsonMapParser.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: mastanca
 */

#include "server_JsonMapParser.h"

#include <rapidjson/rapidjson.h>
#include <stddef.h>

#include "../../common/common_MapConstants.h"


JsonMapParser::JsonMapParser(rapidjson::Document* document) : document(document) {

}

JsonMapParser::~JsonMapParser() {
	delete document;
	document = NULL;
}

void JsonMapParser::parseDocument() {
	const rapidjson::Value& mapJson = (*document)[MAP_NAME];

//	mapView->setId(mapJson[ID_NAME].GetInt());
//	mapView->setName(mapJson[MAPNAME_NAME].GetString());

	const rapidjson::Value& obstaclesJson = mapJson[OBSTACLES_NAME];

	for (rapidjson::SizeType i = 0; i < obstaclesJson.Size(); i++) {
		unsigned int x = obstaclesJson[i][X_NAME].GetInt();
		unsigned int y = obstaclesJson[i][Y_NAME].GetInt();
		int type = obstaclesJson[i][TYPE_NAME].GetInt();

//		ObstacleView *obstacle = new ObstacleView(x, y, (ObstacleViewType)type);
//		mapView->setObstacle(obstacle);
	}
}
