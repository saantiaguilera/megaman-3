
#include <iostream>
#include <gtkmm.h>
#include "../Constants.h"

#include "client_Handler.h"

class Context;

#include "client_Controller.h"
#include "client_Context.h"

#include "controller/client_MainScreenController.h"
#include "client_Client.h"

Client::Client() : currentController(NULL), dispatcher() {
};

Client::~Client()  {
    if (connectionThread)
      connectionThread->join();
};

void Client::attachController(Controller *controller) {
  if (currentController) {
    currentController->setVisibility(false);
    delete currentController;
  }

  currentController = controller;
  currentController->setVisibility(true);
}

void Client::start() {
  auto app = Gtk::Application::create(PACKAGE_NAME);

  MainScreenController *controller = new MainScreenController(*this);
  attachController(controller);

  dispatcher.connect(sigc::mem_fun(*this, &Client::onMessageReceived));

  app->run(*(controller->getView()));
}

bool Client::onMessageReceived() {
  Event *event = Looper::getMainLooper().get();

  if (event) {
    bool consumed = false;

    switch (event->getId()) {
      //Do stuff
      case EVENT_CREATE_CONNECTION:
        if (!connectionThread) {
          connectionThread = new ConnectionThread(this);
          connectionThread->start();
        }
        break;

      default:
        consumed = currentController->onMessageReceived();
    }

    if (consumed)
      Looper::getMainLooper().pop();

    return consumed;
  }
}

void Client::onDataReceived() {
  //We tell the dispatcher that he should check a msg in the main ui thread
	dispatcher.emit();
}
