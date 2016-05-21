#ifndef CLIENT_CLIENT_CLIENT_H_
#define CLIENT_CLIENT_CLIENT_H_

#include <iostream>
#include "controller/client_MainScreenController.h"
#include "../Constants.h"

class Context {
public:
	virtual void attachView(Gtk::Window *view) = 0;

	//I should consult this.
	/*
	I dont like doing a nested tree of view controllers, since the lobby doesnt have any
	relation with the ip:port view or the game view.
	Since they are all independent, some root should handle the flow movements (the routing)
	but since the app->run() blocks me, the only one able to do this
	OOOOOOOOOOOO BOY I HAD A REVELATION, DA WORK HAS STARTED
	*/
	virtual void handleEvent(Event *event) = 0;
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
