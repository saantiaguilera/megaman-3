#include <iostream>

#include "../Constants.h"

#include "event/client_CreateConnectionEvent.h"
#include "event/client_SendKeyMapEvent.h"
#include "event/client_SendChangeWeaponEvent.h"
#include "event/client_QuitEvent.h"
#include "event/client_StartMapEvent.h"
#include "event/client_StopLooperEvent.h"

#include "controller/client_GameController.h"
#include "controller/client_LobbyController.h"
#include "controller/client_MainScreenController.h"

#include "client_Client.h"

Client::Client() : currentController(NULL), dispatcher() {
}

Client::~Client()  {
  if (socket)
    socket->terminate();

  if (connectionThread) {
    connectionThread->join();
    delete connectionThread;
    connectionThread = NULL;
  }

  if (senderThread) {
    if (senderLooper) senderLooper->put(new StopLooperEvent());
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

  if (socket)
    delete socket;

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

void Client::start(int argc, char *argv[]) {
  app = Gtk::Application::create(argc, argv, APP_IS_UNIQUE ? APP_PACKAGE : "");

  onFlowToStart();

  dispatcher.connect(sigc::mem_fun(*this, &Client::onMessageFromDispatcher));

  app->run(*(currentController->getView()));
}

void Client::onCreateConnection(std::string ip, std::string name) {
  if (ip.find_first_of(":") == std::string::npos)
    return;

  if (!connectionThread) {
    clientName = name;
    connectionThread = new ConnectionThread();
    connectionThread->setListener(this);
    connectionThread->setSocket((socket = new Socket()));
    connectionThread->setData(ip.substr(0, ip.find_first_of(":")), ip.substr(ip.find_first_of(":") + 1));
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
    senderThread->setSocket(socket);
    senderThread->setClientName(clientName);
    senderThread->start();
  }

  if (!receiverThread) {
    receiverThread = new ReceiverThread();
    receiverThread->setListener(this);
    receiverThread->setSocket(socket);
    receiverThread->start();
  }
}

void Client::onFlowToStart() {
  //TODO Refactor when I have time. (+ Im doing cleanup in a lot of methods, refactor that too)
  //If we are still at the IP:PORT screen, just remove the connection (because we cant restart a thread)
  if (connectionThread) {
    connectionThread->join();
    delete connectionThread;
    connectionThread = NULL;
  } else { //We are somewhere around our game, we should just go to start. Delete the sender and receiver
    if (senderThread) {
      if (senderLooper) senderLooper->put(new StopLooperEvent());

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
}

void Client::onFlowToLobby() {
  attachController(new LobbyController(this));
}

void Client::onFlowToGame() {
  attachController(new GameController(this));
  receiverThread->setGame(dynamic_cast<GameView*>(currentController->getView()));
}

bool Client::onMessageReceived() {
  bool consumed = false;

  Event *event = Looper::getMainLooper().get();

  if (event) {
    switch (event->getId()) {
      case EVENT_CREATE_CONNECTION:
        onCreateConnection(dynamic_cast<CreateConnectionEvent*>(event)->getIPAndPort(), dynamic_cast<CreateConnectionEvent*>(event)->getName());
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

      case EVENT_SEND_CHANGE_WEAPON:
        senderLooper->put(new SendChangeWeaponEvent(dynamic_cast<SendChangeWeaponEvent*>(event)->getWeaponType()));
        consumed = true;
        break;

      case EVENT_START_GAME:
        senderLooper->put(new StartMapEvent(dynamic_cast<StartMapEvent*>(event)->getMapId()));
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
