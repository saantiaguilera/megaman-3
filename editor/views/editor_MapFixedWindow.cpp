/*
 * MapFixView.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: santi
 */

#include "editor_MapFixedWindow.h"

//Constructor
MapFixedWindow::MapFixedWindow() {}

MapFixedWindow::~MapFixedWindow() {}

MapFixedWindow::MapFixedWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Fixed(cobject), builder(refGlade) {}


void MapFixedWindow::setObstacleViewContainer(ObstacleViewContainer *obstacleViewContainer) {
	obstacleViewContainers->push_back(obstacleViewContainer);
	put(*obstacleViewContainer->getImage(), 0, 0);
}
