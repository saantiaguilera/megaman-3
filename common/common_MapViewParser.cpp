/*
 * EditorMapParser.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "common_MapViewParser.h"

#include <cstdio>
#include <sstream>

#include "common_MapConstants.h"
#include "common_ObstacleView.h"
#include "rapidjson/rapidjson.h"

MapViewParser::MapViewParser() {}

MapViewParser::~MapViewParser() {}

void MapViewParser::parse(rapidjson::Document &document, MapView *mapView) {
	const rapidjson::Value& mapJson = document[MAP_NAME];

	mapView->setId(mapJson[ID_NAME].GetInt());
	mapView->setName(mapJson[MAPNAME_NAME].GetString());
	mapView->setHeight(mapJson[MAPHEIGHT_NAME].GetInt());
	mapView->setWidth(mapJson[MAPWIDTH_NAME].GetInt());


	const rapidjson::Value& obstaclesJson = mapJson[OBSTACLES_NAME];

	for (rapidjson::SizeType i = 0; i < obstaclesJson.Size(); i++) {
		unsigned int x = obstaclesJson[i][X_NAME].GetInt();
		unsigned int y = obstaclesJson[i][Y_NAME].GetInt();
		int type = obstaclesJson[i][TYPE_NAME].GetInt();

		ObstacleView *obstacle = new ObstacleView(x, y, (ObstacleViewType)type);
		mapView->setObstacle(obstacle);
	}
}

void MapViewParser::editorMapWithPath(MapView *mapView, std::string name) {
	rapidjson::Document document;
	readMapFromFile(name, &document);
	parse(document, mapView);
}

rapidjson::Document* MapViewParser::serverMapFromPath(const std::string& name) {
	rapidjson::Document* document = new rapidjson::Document;
	readMapFromFile(name, document);
	return document;
}

void MapViewParser::readMapFromFile(const std::string& name, rapidjson::Document* document) {
	std::stringstream ss;
	ss<<"./json/"<<name;
	std::string path = ss.str();
	std::string filename = path;
	FILE* pFile = fopen(filename.c_str(), "rb");
	char buffer[65536];
	rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
	document->ParseStream<rapidjson::FileReadStream>(is);
}

void MapViewParser::clientMapFromString(MapView *mapView, std::string json) {
	rapidjson::Document document;

	document.Parse(json.c_str());

	parse(document, mapView);
}
