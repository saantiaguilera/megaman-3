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
#include "../models/editor_EditorMapParser.h"
#include "../models/editor_EditorMap.h"


EditorController::EditorController(int argc, char *argv[]) {
	Glib::RefPtr<Gtk::Application> gtkmm_main = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	try {
		builder = Gtk::Builder::create_from_file("editor/editor.glade");
	} catch (Glib::FileError& e) {
		std::cout<<e.what()<<std::endl;
	}

//	mainWindow = 0;
	mapWindow = 0;

//	builder->get_widget_derived("mainWindow", mainWindow);
	builder->get_widget_derived("mapWindow", mapWindow);

//	gtkmm_main->run(*mainWindow);
	gtkmm_main->run(*mapWindow);

//	showMapWindow();
}

EditorController::~EditorController() {}

void EditorController::begin() {}

//Main window delegate
void EditorController::presentMainWindowSavingMap(EditorMap *map) {
	std::cout<<map->getName()<<std::endl;
	showMainWindow();
}

void EditorController::presentMainWindowWithoutSavingMap() {
	showMainWindow();
}

void EditorController::presentMapWindowWithMap(EditorMap *map) {
	std::cout<<map->getName()<<std::endl;
	showMapWindow();
}

void EditorController::showMainWindow() {
	mainWindow->set_visible(true);
	mapWindow->set_visible(false);
}

void EditorController::showMapWindow() {
	mainWindow->set_visible(false);
	mapWindow->set_visible(true);
}

