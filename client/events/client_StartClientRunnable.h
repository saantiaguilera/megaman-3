/*
 * StartClientRunnable.h
 *
 *  Created on: May 16, 2016
 *      Author: santi
 */

#ifndef CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_
#define CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_

#include <iostream>
#include <gtkmm.h>

#define LAYOUT_PATH "res/layout/client_testing.glade"

class StartClientRunnable : public Runnable {
private:
    Gtk::Dialog* pDialog = nullptr;

    void onExit() {
      if(pDialog)
        pDialog->hide();
    }
 public:
	StartClientRunnable() { /* DO SMTH */ }
	virtual ~StartClientRunnable() { /* DO SMTH */ }

	virtual void operator() () {
    auto app = Gtk::Application::create("org.gtkmm.example");

    //Load the GtkBuilder file and instantiate its widgets:
    auto refBuilder = Gtk::Builder::create();
    try {
      refBuilder->add_from_file(LAYOUT_PATH);
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
    refBuilder->get_widget("DialogBasic", pDialog);
    if(pDialog) {
      //Get the GtkBuilder-instantiated Button, and connect a signal handler:
      Gtk::Button* pButton = nullptr;
      refBuilder->get_widget("quit_button", pButton);
      if(pButton) {
        pButton->signal_clicked().connect(sigc::mem_fun(*this, &StartClientRunnable::onExit));
      }

      app->run(*pDialog);
    }

    delete pDialog;
	}
};



#endif /* CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_ */
