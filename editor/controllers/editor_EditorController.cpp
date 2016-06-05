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
#include "../../common/common_MapViewParser.h"
#include "../../common/common_MapView.h"
#include "../../common/common_MapViewJsonWriter.h"


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
	MapViewJsonWriter().writeMapInFilenname(map, "level1.json");
	showMainWindow();
}

void EditorController::presentMainWindowWithoutSavingMap() {
	showMainWindow();
}

void EditorController::presentMapWindowWithMap(MapView *map) {
	showMapWindow();
	mapWindow->setMapView(map);
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

