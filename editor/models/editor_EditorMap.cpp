/*
 * EditorMap.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "editor_EditorMap.h"

EditorMap::EditorMap() {
	// TODO Auto-generated constructor stub

}

EditorMap::~EditorMap() {
	// TODO : delete all vectors
}

void EditorMap::setId(unsigned int aNumber) {
	id = aNumber;
}
void EditorMap::setName(std::string aString) {
	name = aString;
}

void EditorMap::setSpawns(std::vector<EditorObstacle *> *aVector) {
	spawns = aVector;
}
void EditorMap::setNeedles(std::vector<EditorObstacle *> *aVector) {
	needles = aVector;
}
void EditorMap::setPrecipices(std::vector<EditorObstacle *> *aVector) {
	precipices = aVector;
}
void EditorMap::setBlocks(std::vector<EditorObstacle *> *aVector) {
	blocks = aVector;
}
