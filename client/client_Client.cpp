#include <iostream>
#include <gtkmm.h>
#include "../Constants.h"

#include "commons/client_Handler.h"

class Context;

#include "commons/client_Controller.h"
#include "commons/client_Context.h"

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

  MainScreenController *controller = new MainScreenController(this);
  attachController(controller);

  dispatcher.connect(sigc::mem_fun(*this, &Client::onMessageFromDispatcher));

  app->run(*(controller->getView()));
}

bool Client::onMessageReceived() {
  bool consumed = false;

  Event *event = Looper::getMainLooper().get();

  if (event) {

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
  }

  return consumed;
}

void Client::onMessageFromDispatcher() {
  onMessageReceived();
}

void Client::onDataReceived() {
  //We tell the dispatcher that he should check a msg in the main ui thread
	dispatcher.emit();
}
