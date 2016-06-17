/*
 * EditorMap.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "common_MapView.h"

MapView::MapView() {
	obstacles = new std::vector<ObstacleView *>();
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

void MapView::setBackgroundImage(std::string path) {
	backgroundPath = path;
}

void MapView::setFilename(std::string aFilename) {
	filename = aFilename;
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

std::string MapView::getBackgroundImage() {
	return backgroundPath;
}

std::string MapView::getFilename() {
	return filename;
}

unsigned int MapView::getWidth() {
	return width;
}

unsigned int MapView::getHeight() {
	return height;
}

unsigned int MapView::getId() {
	return id;
}

ObstacleView * MapView::getObstacle(int position) {
	return obstacles->at(position);
}

std::vector<ObstacleView *> * MapView::getObstacles() {
	return obstacles;
}
