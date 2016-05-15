/*
 * client_main.h
 *
 *  Created on: May 14, 2016
 *      Author: santiago
 */

#include <iostream>
#include "../Constants.h"
#include <gtkmm.h>

#define LAYOUT_PATH "../res/layout/home_screen.glade"

/*
static void on_button_clicked() {
	if (pDialog)
		pDialog->hide(); //hide() will cause main::run() to end.
}
*/

int main(int argc, char **argv) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv,
			PACKAGE_NAME);

	Gtk::Window* rootView = NULL;

	Glib::RefPtr<Gtk::Builder> viewBuilder = Gtk::Builder::create();

	try {
		viewBuilder->add_from_file(LAYOUT_PATH);
	} catch (const Glib::FileError& ex) {
		std::cout << "FileError: " << ex.what() << std::endl;
		return 1;
	} catch (const Glib::MarkupError& ex) {
		std::cout << "MarkupError: " << ex.what() << std::endl;
		return 1;
	} catch (const Gtk::BuilderError& ex) {
		std::cout << "BuilderError: " << ex.what() << std::endl;
		return 1;
	}

	viewBuilder->get_widget("view_main_screen_root", rootView);

	if (rootView) {/*
		//Get the GtkBuilder-instantiated Button, and connect a signal handler:
		Gtk::Button* pButton = NULL;
		refBuilder->get_widget("quit_button", pButton);
		if (pButton) {
			pButton->signal_clicked().connect(sigc::ptr_fun(on_button_clicked));
		}
*/
		app->run(*rootView);
	}

	delete rootView;

	return 0;
}
