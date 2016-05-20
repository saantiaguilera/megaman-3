#ifndef CLIENT_CLIENT_CLIENT_H_
#define CLIENT_CLIENT_CLIENT_H_

#include <iostream>
#include "controller/client_MainScreenController.h"
#include "../Constants.h"

class Context {
public:
	virtual void attachView(Gtk::Window *view) = 0;
};

/**
 * Pasar a cpp
 */
class Client : public Context {
private:
	Gtk::Window *currentView = NULL;
public:
	Client() {
	 };

	~Client() { };

	virtual void attachView(Gtk::Window *view) {
		if (currentView)
			currentView->hide();

		currentView = view;
		currentView->show();
	}

	void start() {
    auto app = Gtk::Application::create(PACKAGE_NAME);

		MainScreenController controller;
		attachView(controller.getView());

		app->run(*currentView);
	}
private:
	Client(const Client&);
	Client& operator=(const Client&);
};

#endif /* CLIENT_CLIENT_CLIENT_H_ */
