/*
 * EditorMap.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "editor_EditorMap.h"

#include "obstacles/editor_EditorObstacle.h"

EditorMap::EditorMap() {
	spawns = new std::vector<EditorObstacle *>();
	needles = new std::vector<EditorObstacle *>();
	precipices = new std::vector<EditorObstacle *>();
	blocks = new std::vector<EditorObstacle *>();
}

EditorMap::~EditorMap() {
	// TODO : delete all vectors
}

//Setters
void EditorMap::setId(unsigned int aNumber) {
	id = aNumber;
}
void EditorMap::setName(std::string aString) {
	name = aString;
}

//setters
void EditorMap::setSpawn(EditorObstacle *aSpawn) {
	spawns->push_back(aSpawn);
}
void EditorMap::setNeedle(EditorObstacle *aNeedle) {
	needles->push_back(aNeedle);
}
void EditorMap::setPrecipice(EditorObstacle *aPrecipice) {
	precipices->push_back(aPrecipice);
}
void EditorMap::setBlock(EditorObstacle *aBlock) {
	blocks->push_back(aBlock);
}
