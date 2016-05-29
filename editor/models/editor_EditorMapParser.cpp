/*
 * EditorMapParser.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "editor_EditorMapParser.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "editor_EditorMap.h"
#include <string>
#include <iostream>
#include "obstacles/editor_EditorObstacle.h"

#define MAP_NAME "map"
#define ID_NAME "id"
#define MAPNAME_NAME "name"
#define SPAWNS_NAME "spawns"
#define X_NAME "x"
#define Y_NAME "y"
#define SPAWN_TYPE_NAME "type"
#define NEEDLES_NAME "needles"
#define PRECIPICES_NAME "precipices"
#define BLOCKS_NAME "blocks"


EditorMapParser::EditorMapParser() {
	// TODO Auto-generated constructor stub

}

EditorMapParser::~EditorMapParser() {
	// TODO Auto-generated destructor stub
}


void EditorMapParser::editorMapWithPath(EditorMap *editorMap, std::string path) {
	    std::string filename = path;
	    FILE* pFile = fopen(filename.c_str(), "rb");
	    char buffer[65536];
	    rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
	    rapidjson::Document document;
	    document.ParseStream<rapidjson::FileReadStream>(is);



	    editorMap->setId(document[ID_NAME].GetInt());
	    editorMap->setName(document[MAPNAME_NAME].GetString());

	    //TODO: REFACTOR ! quiero ver si funciona bien esto,
	    //Despu'es refactorizo
	    for (int i = 0; i < document[SPAWNS_NAME].Size(); i++) {
	    	Point point;
	    	unsigned int x = document[SPAWNS_NAME][X_NAME];
	    	unsigned int y = document[SPAWNS_NAME][Y_NAME];

	    	point.setX(x);
	    	point.setY(y);

	    	EditorObstacle *obstacle = new EditorObstacle(point, 100, 100);

	    }

	    for (int i = 0; i < document[NEEDLES_NAME].Size(); i++) {
	    	Point point;
	    	unsigned int x = document[NEEDLES_NAME][X_NAME];
	    	unsigned int y = document[NEEDLES_NAME][Y_NAME];

	    	point.setX(x);
	    	point.setY(y);

	    	EditorObstacle *obstacle = new EditorObstacle(point, 100, 100);

	    }

	    for (int i = 0; i < document[PRECIPICES_NAME].Size(); i++) {
	    	Point point;
	    	unsigned int x = document[PRECIPICES_NAME][X_NAME];
	    	unsigned int y = document[PRECIPICES_NAME][Y_NAME];

	    	point.setX(x);
	    	point.setY(y);

	    	EditorObstacle *obstacle = new EditorObstacle(point, 100, 100);

	    }

	    for (int i = 0; i < document[BLOCKS_NAME].Size(); i++) {
	    	Point point;
	    	unsigned int x = document[BLOCKS_NAME][X_NAME];
	    	unsigned int y = document[BLOCKS_NAME][Y_NAME];

	    	point.setX(x);
	    	point.setY(y);

	    	EditorObstacle *obstacle = new EditorObstacle(point, 100, 100);

	    }
}

