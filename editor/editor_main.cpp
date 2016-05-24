/*
 * editor_main.cpp
 *
 *  Created on: May 14, 2016
 *      Author: santi
 */
/*
#include <gtkmm.h>

#include "views/editor_MainWindow.h"
#include <iostream>
#include <exception>

int main(int argc, char *argv[]) {
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
	/*
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

	Gtk::Window window;
	window.set_default_size(1000, 1000);

	return app->run(window);*/
}
*/
