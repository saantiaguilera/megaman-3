#ifndef CLIENT_CLIENT_CLIENT_H_
#define CLIENT_CLIENT_CLIENT_H_

#include <iostream>
#include "controller/client_MainScreenController.h"
#include "../Constants.h"

/**
 * Pasar a cpp
 */
class Client {
public:
	Client() { /* DO SMTH */ };
	~Client() { /* DO SMTH  */};

	void start() {
    auto app = Gtk::Application::create(PACKAGE_NAME);

		MainScreenController controller;

		app->run(*(controller.getView()));
	}
private:
	Client(const Client&);
	Client& operator=(const Client&);
};

#endif /* CLIENT_CLIENT_CLIENT_H_ */
