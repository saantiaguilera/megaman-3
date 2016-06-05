/*
 * MapViewJsonWriter.cpp
 *
 *  Created on: Jun 5, 2016
 *      Author: santi
 */

#include "common_MapViewJsonWriter.h"

#include "rapidjson/rapidjson.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"
#include <iostream>
#include <sstream>
#include "common_MapConstants.h"

MapViewJsonWriter::MapViewJsonWriter() {
	// TODO Auto-generated constructor stub

}

MapViewJsonWriter::~MapViewJsonWriter() {
	// TODO Auto-generated destructor stub
}

void MapViewJsonWriter::writeMapInFilenname(MapView *mapView, std::string filename) {
	rapidjson::Document document;
	std::stringstream ss;
	ss<<"./json/"<<filename;
	std::string path = ss.str();

	FILE* fp = fopen(path.c_str(), "w"); // non-Windows use "w"
	rapidjson::StringBuffer s;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);

	writer.StartObject();
	//{
	writer.Key(MAP_NAME);
	//: {
	writer.StartObject();

	writer.Key(MAPNAME_NAME);
	writer.String(mapView->getName().c_str());

	writer.Key(MAPHEIGHT_NAME);
	writer.Int(mapView->getHeight());

	writer.Key(MAPWIDTH_NAME);
	writer.Int(mapView->getWidth());

	writer.Key(ID_NAME);
	writer.Int(mapView->getId());

	writer.Key(MAPOBSTACLES_NAME);
	writer.StartArray();
	std::vector<ObstacleView *> *obstacles = mapView->getObstacles();

	for(std::vector<ObstacleView *>::iterator it = obstacles->begin(); it != obstacles->end(); ++it) {
		std::cout<<"Pase 2"<<std::endl;

		ObstacleView *obstacleView = *it;
		writer.StartObject();
		writer.Key(X_NAME);
		writer.Int(obstacleView->getPoint().getX());

		writer.Key(Y_NAME);
		writer.Int(obstacleView->getPoint().getY());

		writer.Key(TYPE_NAME);
		writer.Int(obstacleView->getType());
		writer.EndObject();
	}

	writer.EndArray();

	writer.EndObject();
	//}
	writer.EndObject();
	//}
	std::string string = s.GetString();

//TODO : No es la mejor forma creo pero bueno estoy cansado
	fprintf(fp, "%s",string.c_str());

	fclose(fp);
}

