#include <iostream>

#include "../Constants.h"

#include "controller/concurrent/event/client_CreateConnectionEvent.h"

#include "controller/client_GameController.h"
#include "controller/client_LobbyController.h"
#include "controller/client_MainScreenController.h"

#include "client_Client.h"

Client::Client() : currentController(NULL), dispatcher() {
}

Client::~Client()  {
    if (connectionThread)
      connectionThread->join();
}

void Client::attachController(Controller *controller) {
  Controller *old = currentController;

  currentController = controller;
  currentController->getView()->set_title(APP_NAME);
  currentController->setVisibility(true);

  if (old) {
    app->add_window(*(currentController->getView()));
    app->remove_window(*(old->getView()));
    old->setVisibility(false);
    delete old;
  }
}

void Client::start() {
  app = Gtk::Application::create(PACKAGE_NAME);

  attachController(new MainScreenController(this));

  dispatcher.connect(sigc::mem_fun(*this, &Client::onMessageFromDispatcher));

  app->run(*(currentController->getView()));
}

void Client::onCreateConnection(std::string ip) {
  if (!connectionThread) {
    std::cout << ip << std::endl;
    connectionThread = new ConnectionThread(this);
    connectionThread->start();
  }
}

void Client::onFlowToLobby() {
  attachController(new LobbyController(this));
}

void Client::onFlowToGame() {
  attachController(new GameController(this));
}

bool Client::onMessageReceived() {
  bool consumed = false;

  Event *event = Looper::getMainLooper().get();

  if (event) {
    std::cout << "Event found in onMessageReceived, id: " << event->getId() << std::endl;

    switch (event->getId()) {
      //Do stuff
      case EVENT_CREATE_CONNECTION:
        onCreateConnection(dynamic_cast<CreateConnectionEvent*>(event)->getIP());
        consumed = true;
        break;

      case EVENT_FLOW_LOBBY:
        onFlowToLobby();
        consumed = true;
        break;

      case EVENT_FLOW_GAME:
        onFlowToGame();
        consumed = true;
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
