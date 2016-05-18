/*
 * StartClientRunnable.h
 *
 *  Created on: May 16, 2016
 *      Author: santi
 */

#ifndef CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_
#define CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_

#include <iostream>
#include "../../Constants.h"
#include <gtkmm.h>

#define LAYOUT_PATH "res/layout/home_screen.glade"
#define VIEW_ROOT "client_home_screen_root_view"

class StartClientRunnable : public Runnable {
 public:
	StartClientRunnable() { /* DO SMTH */ }
	virtual ~StartClientRunnable() { /* DO SMTH */ }

	virtual void operator() () {
		auto app = Gtk::Application::create("org.gtkmm.examples.base");

		Gtk::Window window;
		window.set_default_size(200, 200);

		app->run(window);
	}
private:
	static void onEnterPressed(GtkEntry *entry,
            gpointer  user_data) {
		std::cout << "Enter was pressed" << std::endl;
	}
};



#endif /* CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_ */
