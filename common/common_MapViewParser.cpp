/*
 * EditorMapParser.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "common_MapViewParser.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "common_MapView.h"
#include <string>
#include <iostream>
#include "common_ObstacleView.h"
#include <sstream>
#include "common_MapConstants.h"

MapVeiwParser::MapVeiwParser() {}

MapVeiwParser::~MapVeiwParser() {}


void MapVeiwParser::editorMapWithPath(MapView *MapView, std::string name) {
	std::stringstream ss;
	ss<<"./json/"<<name;
	std::cout<<"llegue1"<<std::endl;
	std::string path = ss.str();
	std::string filename = path;
	FILE* pFile = fopen(filename.c_str(), "rb");
	std::cout<<"llegue2"<<std::endl;

	char buffer[65536];
	rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
	rapidjson::Document document;
	document.ParseStream<rapidjson::FileReadStream>(is);
	const rapidjson::Value& mapJson = document[MAP_NAME];

	MapView->setId(mapJson[ID_NAME].GetInt());
	MapView->setName(mapJson[MAPNAME_NAME].GetString());

	std::cout<<"llegue3"<<std::endl;


	const rapidjson::Value& obstaclesJson = mapJson[OBSTACLES_NAME];



	for (rapidjson::SizeType i = 0; i < obstaclesJson.Size(); i++) {
		unsigned int x = obstaclesJson[i][X_NAME].GetInt();
		unsigned int y = obstaclesJson[i][Y_NAME].GetInt();
		int type = obstaclesJson[i][TYPE_NAME].GetInt();

		std::cout<<"llegue4"<<std::endl;


		ObstacleView *obstacle = new ObstacleView(x, y, (ObstacleViewType)type);
		MapView->setObstacle(obstacle);
	}
//
//	const rapidjson::Value& needlesJson = mapJson[NEEDLES_NAME];
//
//	for (rapidjson::SizeType i = 0; i < needlesJson.Size(); i++) {
//		std::cout<<"aca rompe todo"<<std::endl;
//
//		unsigned int x = needlesJson[i][X_NAME].GetInt();
//		unsigned int y = needlesJson[i][Y_NAME].GetInt();
//
//		EditorObstacle *obstacle = new EditorObstacle(x, y, 100, 100);
//		editorMap->setNeedle(obstacle);
//
//	}
//
//	const rapidjson::Value& precipicesJson = mapJson[PRECIPICES_NAME];
//
//	for (rapidjson::SizeType i = 0; i < precipicesJson.Size(); i++) {
//		unsigned int x = precipicesJson[i][X_NAME].GetInt();
//		unsigned int y = precipicesJson[i][Y_NAME].GetInt();
//
//		EditorObstacle *obstacle = new EditorObstacle(x, y, 100, 100);
//		editorMap->setPrecipice(obstacle);
//	}
//
//	const rapidjson::Value& blocksJson = mapJson[BLOCKS_NAME];
//
//	for (rapidjson::SizeType i = 0; i < blocksJson.Size(); i++) {
//		unsigned int x = blocksJson[i][X_NAME].GetInt();
//		unsigned int y = blocksJson[i][Y_NAME].GetInt();
//
//		EditorObstacle *obstacle = new EditorObstacle(x, y, 100, 100);
//		editorMap->setBlock(obstacle);
//	}
}
