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

//
//void MapView::setSpawn(EditorObstacle *aSpawn) {
//	spawns->push_back(aSpawn);
//}
//void MapView::setNeedle(EditorObstacle *aNeedle) {
//	needles->push_back(aNeedle);
//}
//void MapView::setPrecipice(EditorObstacle *aPrecipice) {
//	precipices->push_back(aPrecipice);
//}
//void MapView::setBlock(EditorObstacle *aBlock) {
//	blocks->push_back(aBlock);
//}

//Getters
std::string MapView::getName() {
	return name;
}
