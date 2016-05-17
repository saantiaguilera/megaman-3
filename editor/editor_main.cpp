/*
 * editor_main.cpp
 *
 *  Created on: May 14, 2016
 *      Author: santi
 */

#include <gtkmm.h>

int main(int argc, char *argv[]) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  Gtk::Window window;
  window.set_default_size(1000, 1000);

  return app->run(window);
}
