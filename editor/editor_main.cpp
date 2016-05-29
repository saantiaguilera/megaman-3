/*
 * editor_main.cpp
 *
 *  Created on: May 14, 2016
 *      Author: santi
 */

#include <gtkmm.h>

#include "views/editor_MainWindow.h"
#include <iostream>
#include <exception>
#include "models/editor_EditorMapParser.h"
#include "models/editor_EditorMap.h"

int main(int argc, char *argv[]) {
	EditorMapParser mapParser;
	EditorMap *map = new EditorMap();

	mapParser.editorMapWithPath(map, "level1.json");

	delete map;

	Gtk::Main kit(argc, argv);

	Glib::RefPtr<Gtk::Builder> builder;

	try {
		builder = Gtk::Builder::create_from_file("editor/editor.glade");
	} catch (Glib::FileError& e) {
		std::cout<<e.what()<<std::endl;
	}

	MainWindow *mainWindow = 0;

	builder->get_widget_derived("mainWindow", mainWindow);

	Gtk::Main::run(*mainWindow);

	return EXIT_SUCCESS;
}

