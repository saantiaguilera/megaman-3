/*
 * MapFixView.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: santi
 */

#include "editor_MapFixedWindow.h"

#include <iostream>
#include "../../common/common_MapConstants.h"

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
	mapView->getObstacles()->clear();

	for(std::vector<ObstacleViewContainer *>::iterator it = obstacleViewContainers->begin(); it != obstacleViewContainers->end(); ++it) {
		ObstacleViewContainer*obstacleViewContainer = *it;

		mapView->getObstacles()->push_back(obstacleViewContainer->getObstacleView());
	}

	return mapView;
}

void MapFixedWindow::removeAllChildViews() {
	std::vector<Gtk::Widget *> children = get_children();

	for(std::vector<Gtk::Widget *>::iterator it = children.begin(); it != children.end(); ++it) {
		Gtk::Widget *child = *it;

		remove(*child);
	}

	for(std::vector<ObstacleViewContainer *>::iterator it = obstacleViewContainers->begin(); it != obstacleViewContainers->end(); ++it) {
		ObstacleViewContainer*obstacleViewContainer = *it;

		delete obstacleViewContainer;
	}

	obstacleViewContainers->clear();
}

ObstacleViewContainer *MapFixedWindow::obstacleViewContainerWithPosition(int aX, int aY) {
	for(std::vector<ObstacleViewContainer *>::iterator it = obstacleViewContainers->begin(); it != obstacleViewContainers->end(); ++it) {
		ObstacleViewContainer *obstacleViewContainer = *it;

		int x = obstacleViewContainer->getObstacleView()->getPoint().getX();
		int y = obstacleViewContainer->getObstacleView()->getPoint().getY();

		bool aXandAYAreInRange = (x < aX) && (y < aY) && (aX < (x + kObstacleSize)) && (aY < (y + kObstacleSize));

		if (aXandAYAreInRange) {
			return obstacleViewContainer;
		}
	}
	return NULL;
}

