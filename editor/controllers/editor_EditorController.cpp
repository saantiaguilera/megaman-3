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


EditorController::EditorController() {
	try {
		builder = Gtk::Builder::create_from_file("editor/editor.glade");
	} catch (Glib::FileError& e) {
		std::cout<<e.what()<<std::endl;
	}

	mainWindow = 0;
	mapWindow = 0;

	builder->get_widget_derived("mainWindow", mainWindow);
	builder->get_widget_derived("mapWindow", mapWindow);

	Gtk::Main::run(*mainWindow);
}

EditorController::~EditorController() {
	// TODO Auto-generated destructor stub
}

void EditorController::begin() {
//	EditorMapParser mapParser;
//	EditorMap *map = new EditorMap();
//
//	mapParser.editorMapWithPath(map, "level1.json");
//
//	delete map;
//
//	Gtk::Main kit(argc, argv);
//
//	Glib::RefPtr<Gtk::Builder> builder;
//
//	try {
//		builder = Gtk::Builder::create_from_file("editor/editor.glade");
//	} catch (Glib::FileError& e) {
//		std::cout<<e.what()<<std::endl;
//	}
//
//	MainWindow *mainWindow = 0;
//
//	builder->get_widget_derived("mainWindow", mainWindow);
//	Gtk::Main::run(*mainWindow);
//	Gtk::Main::run(*mainWindow2);

//	showMainWindow();
}

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
	mainWindow->show();
	mapWindow->hide();
}

void EditorController::showMapWindow() {
	mainWindow->hide();
	mapWindow->show();
}

