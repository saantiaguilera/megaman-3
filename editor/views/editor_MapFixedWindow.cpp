/*
 * MapFixView.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: santi
 */

#include "editor_MapFixedWindow.h"

#include <iostream>
#include <sstream>
#include <math.h>
#include "../../common/common_MapConstants.h"

//Constructor
MapFixedWindow::MapFixedWindow() {}

MapFixedWindow::~MapFixedWindow() {
	delete obstacleViewContainers;
}

MapFixedWindow::MapFixedWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Fixed(cobject), builder(refGlade) {
	obstacleViewContainers = new std::vector<ObstacleViewContainer *>();
	// backgroundImages = new std::std::vector<Gtk::Image *>();
}

//Setters
void MapFixedWindow::setObstacleViewContainer(ObstacleViewContainer *obstacleViewContainer) {
	obstacleViewContainers->push_back(obstacleViewContainer);

 	ObstacleView *obstacleView = obstacleViewContainer->getObstacleView();

 	int x = obstacleView->getPoint().getX();
 	int y = obstacleView->getPoint().getY();

	put(*obstacleViewContainer->getImage(), x, y);

	cropMapBackground();
}

void MapFixedWindow::cropMapBackground() {
	std::string path = mapView->getBackgroundImage();

	Glib::RefPtr<Gdk::Pixbuf> backgroundImagePixbuf = Gdk::Pixbuf::create_from_file(path);

	int mapWidth = this->mapWidth() + TERRAIN_TILE_SIZE;
	int mapHeight = this->mapHeight() + TERRAIN_TILE_SIZE;

	int backgroundImagePixbufWidth = backgroundImagePixbuf->get_width();
	int backgroundImagePixbufHeight = backgroundImagePixbuf->get_height();

	int ratioMosaicPixbuffWidth = ceil((float)mapWidth/(float)backgroundImagePixbufWidth);
	int ratioMosaicPixbuffHeight = ceil((float)mapHeight/(float)backgroundImagePixbufHeight);

	Glib::RefPtr<Gdk::Pixbuf> mosaicPixbuff = Gdk::Pixbuf::create(Gdk::COLORSPACE_RGB, true, 8, ratioMosaicPixbuffWidth * backgroundImagePixbufWidth, ratioMosaicPixbuffHeight * backgroundImagePixbufHeight);

	for (int x = 0 ; x < ratioMosaicPixbuffWidth ; ++x) {
		for (int y = 0 ; y < ratioMosaicPixbuffHeight ; ++y) {
			backgroundImagePixbuf->copy_area(0, 0, backgroundImagePixbufWidth, backgroundImagePixbufHeight, mosaicPixbuff, x * backgroundImagePixbufWidth, y * backgroundImagePixbufHeight);
		}
	}

	Glib::RefPtr<Gdk::Pixbuf> cropMosaicPixbuf = Gdk::Pixbuf::create_subpixbuf(mosaicPixbuff, 0, 0, mapWidth, mapHeight);

	backgroundImage->set(cropMosaicPixbuf);
}

void MapFixedWindow::setMapView(MapView *aMapView) {
	mapView = aMapView;

	set_size_request(mapView->getWidth(), mapView->getHeight());

	backgroundImage = new Gtk::Image();

	cropMapBackground();

	put(*backgroundImage, 0, 0);
	backgroundImage->show();

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

void MapFixedWindow::removeObstacleContainerView(ObstacleViewContainer *obstacleViewContainer) {
	remove(*obstacleViewContainer->getImage());
	obstacleViewContainers->erase(std::remove(obstacleViewContainers->begin(), obstacleViewContainers->end(), obstacleViewContainer), obstacleViewContainers->end());

	delete obstacleViewContainer;

	cropMapBackground();
}

ObstacleViewContainer *MapFixedWindow::obstacleViewContainerWithPosition(int aX, int aY) {
	for(std::vector<ObstacleViewContainer *>::iterator it = obstacleViewContainers->begin(); it != obstacleViewContainers->end(); ++it) {
		ObstacleViewContainer *obstacleViewContainer = *it;

		int x = obstacleViewContainer->getObstacleView()->getPoint().getX();
		int y = obstacleViewContainer->getObstacleView()->getPoint().getY();

		bool aXandAYAreInRange = (x < aX) && (y < aY) && (aX < (x + TERRAIN_TILE_SIZE)) && (aY < (y + TERRAIN_TILE_SIZE));

		if (aXandAYAreInRange) {
			return obstacleViewContainer;
		}
	}

	return NULL;
}

int MapFixedWindow::mapWidth() {
	int maxWidth= 0;

	for(std::vector<ObstacleViewContainer *>::iterator it = obstacleViewContainers->begin(); it != obstacleViewContainers->end(); ++it) {
		ObstacleViewContainer *obstacleViewContainer = *it;
		int x = obstacleViewContainer->getObstacleView()->getPoint().getX();

		maxWidth = (x > maxWidth) ? x : maxWidth;
	}

	return maxWidth;
}

int MapFixedWindow::mapHeight() {
	int maxHeight= 0;

	for(std::vector<ObstacleViewContainer *>::iterator it = obstacleViewContainers->begin(); it != obstacleViewContainers->end(); ++it) {
		ObstacleViewContainer *obstacleViewContainer = *it;
		int y = obstacleViewContainer->getObstacleView()->getPoint().getY();

		maxHeight = (y > maxHeight) ? y : maxHeight;
	}

	return maxHeight;
}

void MapFixedWindow::setBackgroundImage(std::string aBackgroundImagePath) {
	mapView->setBackgroundImage(aBackgroundImagePath);

	cropMapBackground();
}
