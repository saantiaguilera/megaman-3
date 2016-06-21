/*
 * EditorController.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "editor_EditorController.h"

#include <gtkmm.h>
#include "../views/editor_MainWindow.h"
#include <iostream>
#include <exception>
#include <vector>
#include "../../common/common_MapViewParser.h"
#include "../../common/common_MapView.h"
#include "../../common/common_MapViewJsonWriter.h"
#include "../../common/common_MapConstants.h"



EditorController::EditorController(int argc, char *argv[]) {
	gtkmm_main = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	try {
		builder = Gtk::Builder::create_from_file("editor/editor.glade");
	} catch (Glib::FileError& e) {
		std::cout<<e.what()<<std::endl;
	}

	builder->get_widget_derived("mainWindow", mainWindow);
	builder->get_widget_derived("mapWindow", mapWindow);

	mainWindow->setDelegate(this);
	mapWindow->setDelegate(this);
}

EditorController::~EditorController() {}

void EditorController::begin() {
	gtkmm_main->run(*mainWindow);
}

//Main window delegate
void EditorController::presentMainWindowSavingMap(MapView *map) {
	translateNonObstacleToCenter(map);
	MapViewJsonWriter().writeMapInFilenname(map, map->getFilename());
	showMainWindow();
}

void EditorController::presentMainWindowWithoutSavingMap() {
	showMainWindow();
}

void EditorController::presentMapWindowWithMap(MapView *map) {
	showMapWindow();
	translateNonObstacleToCorner(map);
	mapWindow->setMapView(map);

	std::cout<<"map id " <<map->getId()<< std::endl;

	if (map->getId() == 1) {
		std::cout<<"ObstacleViewTtpe "<< ObstacleViewTypeFireman;
		mapWindow->setBossType(ObstacleViewTypeFireman, false);
	} else

	if (map->getId() == 2) {
		mapWindow->setBossType(ObstacleViewTypeMagnetman, false);
	} else

	if (map->getId() == 3) {
		mapWindow->setBossType(ObstacleViewTypeRingman, false);
	} else

	if (map->getId() == 4) {
		mapWindow->setBossType(ObstacleViewTypeSparkman, false);
	} else

	if (map->getId() == 5) {
		mapWindow->setBossType(ObstacleViewTypeBombman, false);
	} else

	if (map->getId() == 6) {
		std::cout<<"ObstacleViewTtpe "<< ObstacleViewTypeFireman;
		mapWindow->setBossType(ObstacleViewTypeFireman, true);
	} else

	if (map->getId() == 7) {
		mapWindow->setBossType(ObstacleViewTypeMagnetman, true);
	} else

	if (map->getId() == 8) {
		mapWindow->setBossType(ObstacleViewTypeRingman, true);
	} else

	if (map->getId() == 9) {
		mapWindow->setBossType(ObstacleViewTypeSparkman, true);
	} else

	if (map->getId() == 10) {
		mapWindow->setBossType(ObstacleViewTypeBombman, true);
	}

}

void EditorController::presentBossViewWithBossType(MapView *map, ObstacleViewType bossType) {
	translateNonObstacleToCenter(map);
	MapViewJsonWriter().writeMapInFilenname(map, map->getFilename());
	showMainWindow();

	mainWindow->presentMapWithBossType(bossType);
}


void EditorController::showMainWindow() {
	mainWindow->set_visible(true);
	mapWindow->set_visible(false);
	gtkmm_main->add_window(*mainWindow);
	gtkmm_main->remove_window(*mapWindow);
}

void EditorController::showMapWindow() {
	mapWindow->set_visible(true);
	mainWindow->set_visible(false);
	gtkmm_main->add_window(*mapWindow);
	gtkmm_main->remove_window(*mainWindow);
}

void EditorController::translateNonObstacleToCenter(MapView *mapView) {
	std::vector<ObstacleView *> *obstacles = mapView->getObstacles();

	for(std::vector<ObstacleView *>::iterator it = obstacles->begin(); it != obstacles->end(); ++it) {
		ObstacleView *obstacleView = *it;

		if (centerObstacleViewType(obstacleView->getType())) {
			int centerX = obstacleView->getPoint().getX() + (TERRAIN_TILE_SIZE / 2);
			int centerY = obstacleView->getPoint().getY() + (TERRAIN_TILE_SIZE / 2);
			obstacleView->setPosition(centerX, centerY);
		}
	}
}

void EditorController::translateNonObstacleToCorner(MapView *mapView) {
	std::vector<ObstacleView *> *obstacles = mapView->getObstacles();

	for(std::vector<ObstacleView *>::iterator it = obstacles->begin(); it != obstacles->end(); ++it) {
		ObstacleView *obstacleView = *it;

		if (centerObstacleViewType(obstacleView->getType())) {
			int centerX = obstacleView->getPoint().getX() - (TERRAIN_TILE_SIZE / 2);
			int centerY = obstacleView->getPoint().getY() - (TERRAIN_TILE_SIZE / 2);
			obstacleView->setPosition(centerX, centerY);
		}
	}
}



bool EditorController::centerObstacleViewType(ObstacleViewType type) {
	return true;
}
