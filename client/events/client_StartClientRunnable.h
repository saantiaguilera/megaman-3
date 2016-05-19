/*
 * StartClientRunnable.h
 *
 *  Created on: May 16, 2016
 *      Author: santi
 */

#ifndef CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_
#define CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_

#include "../../Constants.h"
#include "../concurrent/client_Runnable.h"
#include <iostream>
#include <gtkmm.h>

#define PATH_LAYOUT "res/layout/home_screen.glade"
#define PATH_ROOT_VIEW "client_home_screen_root_view"
#define PATH_EDIT_TEXT_VIEW "client_home_screen_edit_text"

class StartClientRunnable : public Runnable {
private:
    Gtk::Window* mainWindow = nullptr;
    Gtk::Entry* editText = nullptr;

    void onEnterPressed() {
      std::cout << editText->get_text() << std::endl;
    }
    
 public:
	StartClientRunnable() { /* DO SMTH */ }
	virtual ~StartClientRunnable() { /* DO SMTH */ }

	virtual void operator() () {
    auto app = Gtk::Application::create(PACKAGE_NAME);

    //Load the GtkBuilder file and instantiate its widgets:
    auto refBuilder = Gtk::Builder::create();
    try {
      refBuilder->add_from_file(PATH_LAYOUT);
    } catch(const Glib::FileError& ex) {
      std::cout << "FileError: " << ex.what() << std::endl;
      return;
    } catch(const Glib::MarkupError& ex) {
      std::cout << "MarkupError: " << ex.what() << std::endl;
      return;
    } catch(const Gtk::BuilderError& ex) {
      std::cout << "BuilderError: " << ex.what() << std::endl;
      return;
    }

    //Get the GtkBuilder-instantiated Dialog:
    refBuilder->get_widget(PATH_ROOT_VIEW, mainWindow);
    if(mainWindow) {
      //Get the GtkBuilder-instantiated Button, and connect a signal handler:
      refBuilder->get_widget(PATH_EDIT_TEXT_VIEW, editText);
      if(editText) {
        editText->signal_activate().connect(sigc::mem_fun(*this, &StartClientRunnable::onEnterPressed));
      }

      app->run(*mainWindow);
    }

    delete mainWindow;
	}
};

#endif /* CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_ */
