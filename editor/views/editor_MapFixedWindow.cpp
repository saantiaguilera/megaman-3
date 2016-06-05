/*
 * MapFixView.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: santi
 */

#include "editor_MapFixedWindow.h"

#include <iostream>

//Constructor
MapFixedWindow::MapFixedWindow() {}

MapFixedWindow::~MapFixedWindow() {
	delete obstacleViewContainers;
}

MapFixedWindow::MapFixedWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Fixed(cobject), builder(refGlade) {
	obstacleViewContainers = new std::vector<ObstacleViewContainer *>();

}

//Setters
void MapFixedWindow::setObstacleViewContainer(ObstacleViewContainer *obstacleViewContainer) {
	obstacleViewContainers->push_back(obstacleViewContainer);

 	ObstacleView *obstacleView = obstacleViewContainer->getObstacleView();

 	int x = obstacleView->getPoint().getX();
 	int y = obstacleView->getPoint().getY();

	put(*obstacleViewContainer->getImage(), x, y);
}

void MapFixedWindow::setMapView(MapView *aMapView) {
	mapView = aMapView;

	set_size_request(mapView->getWidth(), mapView->getHeight());
	std::vector<ObstacleView *> *obstacles = mapView->getObstacles();

	for(std::vector<ObstacleView *>::iterator it = obstacles->begin(); it != obstacles->end(); ++it) {
		ObstacleView *obstacleView = *it;

	    ObstacleViewContainer *obstacleViewContainer = new ObstacleViewContainer(obstacleView);
	    setObstacleViewContainer(obstacleViewContainer);
	}
}

MapView *MapFixedWindow::saveMapView() {
	for(std::vector<ObstacleViewContainer *>::iterator it = obstacleViewContainers->begin(); it != obstacleViewContainers->end(); ++it) {
		ObstacleViewContainer*obstacleViewContainer = *it;

		mapView->getObstacles()->clear();

		mapView->getObstacles()->push_back(obstacleViewContainer->getObstacleView());
	}


	return mapView;
}
