#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <string>
#include <ctype.h>

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
    if (senderLooper){
      senderLooper->put(new StopLooperEvent());
      senderThread->notify();
    }
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
  int appArgs = 1;

  if (argc > 1)
    gameFramesPerSecond = atoi(argv[1]);

  app = Gtk::Application::create(appArgs, argv, APP_IS_UNIQUE ? APP_PACKAGE : "");

  onFlowToStart();

  dispatcher.connect(sigc::mem_fun(*this, &Client::onMessageFromDispatcher));

  app->run(*(currentController->getView()));
}

bool Client::isIPValid(std::string data) {
  try {
    if (data.find_first_of(":") == std::string::npos)
      return false;

    std::string address = data.substr(0, data.find_first_of(":"));
    std::string port = data.substr(data.find_first_of(":") + 1);

    std::vector<std::string> arr;
    int k = 0;
    arr.push_back(std::string());
    for (std::string::const_iterator i = address.begin(); i != address.end(); ++i) {
        if (*i == '.') {
            ++k;
            arr.push_back(std::string());
            if (k == 4)
              return false;
            continue;
        }
        if (*i >= '0' && *i <= '9')
            arr[k] += *i;
        else return false;
        if (arr[k].size() > 3)
            return false;
    }
    if (k != 3)
        return false;

    for (int i = 0; i != 4; ++i) {
        const char* nPtr = arr[i].c_str();
        char* endPtr = 0;
        const unsigned long a = ::strtoul(nPtr, &endPtr, 10);
        if (nPtr == endPtr)
            return false;

        if (a > 255)
            return false;
    }

    for(std::string::const_iterator portIterator = port.begin(); portIterator != port.end(); ++portIterator)
        if (!isdigit(*portIterator)) return false;

    return true;
  } catch (std::exception e) {
    return false;
  }
}

void Client::onCreateConnection(std::string ip, std::string name) {
  if (isIPValid(ip) && !connectionThread) {
    clientName = name;
    connectionThread = new ConnectionThread();
    connectionThread->setListener(this);
    connectionThread->setSocket((socket = new Socket()));
    connectionThread->setData(ip.substr(0, ip.find_first_of(":")), ip.substr(ip.find_first_of(":") + 1));
    connectionThread->start();
  } else {
    Looper::getMainLooper().put(new ConnectionEvent(RESULT_ERROR));
    onDataReceived();
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
      if (senderLooper) {
        senderLooper->put(new StopLooperEvent());
        senderThread->notify();
      }

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
  GameController *gameController = new GameController(this);

  attachController(gameController);

  if (gameFramesPerSecond > 0)
    gameController->setFramesPerSecond(gameFramesPerSecond);

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
        senderThread->notify();
        consumed = true;
        break;

      case EVENT_SEND_CHANGE_WEAPON:
        senderLooper->put(new SendChangeWeaponEvent(dynamic_cast<SendChangeWeaponEvent*>(event)->getWeaponType()));
        senderThread->notify();
        consumed = true;
        break;

      case EVENT_START_GAME:
        senderLooper->put(new StartMapEvent(dynamic_cast<StartMapEvent*>(event)->getMapId()));
        senderThread->notify();
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
