/*
 * EditorMap.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "common_MapView.h"

MapView::MapView() {
	obstacles = new std::vector<ObstacleView *>();
//	spawns = new std::vector<EditorObstacle *>();
//	needles = new std::vector<EditorObstacle *>();
//	precipices = new std::vector<EditorObstacle *>();
//	blocks = new std::vector<EditorObstacle *>();
}

MapView::~MapView() {
	delete obstacles;
}

//Setters
void MapView::setId(unsigned int aNumber) {
	id = aNumber;
}
void MapView::setName(std::string aString) {
	name = aString;
}

void MapView::setObstacle(ObstacleView *obstacle) {
	obstacles->push_back(obstacle);
}

void MapView::setHeight(unsigned int aHeight) {
	height = aHeight;
}
void MapView::setWidth(unsigned int aWidth) {
	width = aWidth;
}

//Getters
std::string MapView::getName() {
	return name;
}
