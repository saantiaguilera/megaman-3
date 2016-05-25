#include <iostream>

#include "../Constants.h"

#include "controller/concurrent/event/client_CreateConnectionEvent.h"
#include "controller/concurrent/event/client_SendKeyMapEvent.h"
#include "controller/concurrent/event/client_QuitEvent.h"

#include "controller/client_GameController.h"
#include "controller/client_LobbyController.h"
#include "controller/client_MainScreenController.h"

#include "client_Client.h"

Client::Client() : currentController(NULL), dispatcher() {
}

Client::~Client()  {
  if (socket)
    delete socket;

  if (connectionThread) {
    connectionThread->join();
    delete connectionThread;
    connectionThread = NULL;
  }

  if (senderThread) {
    senderThread->join();
    delete senderThread;
    senderThread = NULL;
    delete senderLooper;
    senderLooper = NULL;
  }

  if (receiverThread) {
    receiverThread->join();
    delete receiverThread;
    receiverThread = NULL;
  }

  delete currentController;
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

  onFlowToStart();

  dispatcher.connect(sigc::mem_fun(*this, &Client::onMessageFromDispatcher));

  app->run(*(currentController->getView()));
}

void Client::onCreateConnection(std::string ip) {
  if (!connectionThread) {
    std::cout << ip << std::endl;
    connectionThread = new ConnectionThread();
    connectionThread->setListener(this);
    connectionThread->setSocket(NULL); //TODO
    connectionThread->start();
  }
}

void Client::createSenderAndReceiver() {
  if (connectionThread) {
    connectionThread->join();
    delete connectionThread;
    connectionThread = NULL;
  }

  if (!senderThread) {
    senderThread = new SenderThread((senderLooper = new Looper()));
    senderThread->setSocket(NULL); //TODO
    senderThread->start();
  }

  if (!receiverThread) {
    receiverThread = new ReceiverThread();
    receiverThread->setListener(this);
    receiverThread->setSocket(NULL); //TODO
    receiverThread->start();
  }
}

void Client::onFlowToStart() {
    if (senderThread) {
      senderThread->join();
      delete senderThread;
      senderThread = NULL;
      delete senderLooper;
      senderLooper = NULL;
    }

    if (receiverThread) {
      receiverThread->join();
      delete receiverThread;
      receiverThread = NULL;
    }

    attachController(new MainScreenController(this));
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
    std::cout << "Event found in Client::onMessageReceived, id: " << event->getId() << std::endl;

    switch (event->getId()) {
      //Do stuff
      //TODO refactor the consumed var unless i found a case where it hasnt has to be consumed
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

      case EVENT_SEND_KEY_MAP:
        senderLooper->put(new SendKeyMapEvent(dynamic_cast<SendKeyMapEvent*>(event)->getKeyMap()));
        consumed = true;
        break;

      case EVENT_CONNECTION_ACCEPTED: //consumed = false;
        createSenderAndReceiver();
        break;

      case EVENT_CONNECTION_REFUSED: //consumed = false
      case EVENT_CONNECTION_SHUTDOWN: //consumed = false
        onFlowToStart();
        break;

    }

    if (!consumed)
      consumed = currentController->onMessageReceived();

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
