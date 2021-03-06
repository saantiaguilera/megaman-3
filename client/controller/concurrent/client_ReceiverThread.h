#ifndef CLIENT_EVENTS_CLIENT_RECEIVERTHREAD_H_
#define CLIENT_EVENTS_CLIENT_RECEIVERTHREAD_H_

#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>

#include "../../../common/common_Socket.h"
#include "../../concurrent/client_Looper.h"
#include "../../../common/common_Thread.h"
#include "../../concurrent/client_Event.h"

#include "../../event/client_DisconnectedPlayerEvent.h"
#include "../../event/client_NewPlayerEvent.h"
#include "../../event/client_ConnectionEvent.h"
#include "../../event/client_FlowEvent.h"
#include "../../event/client_ReceivedMapEvent.h"
#include "../../event/client_AmmoChangeEvent.h"
#include "../../event/client_GaugeChangeEvent.h"
#include "../../event/client_HpChangeEvent.h"
#include "../../event/client_LifeChangeEvent.h"
#include "../../event/client_UserHasDefinedIdEvent.h"

#include "../../view/client_GameView.h"

#include "client_ReceiverContract.h"
#include "../../../common/common_MessageProtocol.h"

#include <unistd.h>

#define DELAY_BOSS_CHAMBER_SLEEP_TIME 600 //In ms

class ReceiverThread : public Thread {
private:
  ReceiverContract *listener;
  Looper *handlerLooper;
  Socket *socket;

  GameView * gameView = NULL;

  void dispatchEvent(Event *event) {
    if (listener) {
      if (handlerLooper)
        handlerLooper->put(event);
      else Looper::getMainLooper().put(event);

      listener->onDataReceived();
    }
  }

protected:
  virtual void run() {
    bool isAtGame = false;
    dispatchEvent(new FlowEvent(FLOW_LOBBY));

    try {
      while (socket && socket->isActive()) {
        //Well, run should only have this while and everything should happen from server data
        // Receive message code
        int messageCode;
        int result = socket->receive((char*) &messageCode, sizeof(int));

        if (result <= 0) {
          throw std::logic_error("Socket finished with result <= 0 when trying to fetch messageCode");
        }

        messageCode = ntohl(messageCode);

        unsigned int messageLength;
        // Receive message length
        result = socket->receive((char*) &messageLength, sizeof(unsigned int));

        if (result <= 0) {
          std::stringstream ss;
          ss << "Socket finished with result <= 0 when trying to fetch messageLength. Message code was " << messageCode;
          throw std::logic_error(ss.str());
        }

        messageLength = ntohl(messageLength);

        std::string json;
        char* buffer = new char[messageLength + 1];
        buffer[messageLength] = 0;
        memset(&buffer[0], 0, sizeof(*buffer));
        result = socket->receive(&buffer[0], messageLength);

        if (result <= 0) {
          std::stringstream ss;
          ss << "Socket finished with result <= 0 when trying to fetch JSON Data. Message code was " << messageCode << ". Desired length was " << messageLength;
          throw std::logic_error(ss.str());
        }

        json += buffer;

        switch (messageCode) {
          //Do something
          case NEW_PLAYER:
            dispatchEvent(new NewPlayerEvent(json));
            break;

          case DISCONNECTED_PLAYER:
            dispatchEvent(new DisconnectedPlayerEvent(json));
            break;

          case CONNECTED_PLAYER_ID:
            dispatchEvent(new UserHasDefinedIdEvent(json));
            break;

          case START_GAME:
            dispatchEvent(new FlowEvent(FLOW_GAME));
            dispatchEvent(new ReceivedMapEvent(json));
            isAtGame = true;
            break;

          case ENTERED_BOSS_CHAMBER:
            if (isAtGame) {
              dispatchEvent(new ReceivedMapEvent(json));
              usleep(1000 * DELAY_BOSS_CHAMBER_SLEEP_TIME); //1ms * n ms
              //Because by the time the ReceivedMapEvent reaches the main thread it has
              //probably already created some objects and we dont have time to update the running flag in time
            }
            break;

          case END_GAME:
            if (isAtGame) {
              dispatchEvent(new FlowEvent(FLOW_LOBBY));
              isAtGame = false;
              gameView = NULL;
            }
            break;

          case UPDATE_MOVEMENTS:
            if (isAtGame) {
              while (!gameView || !gameView->isRunning()) {}
              gameView->moveViewFromJSON(json);
            }
            break;

          case OBJECT_CREATED:
            if (isAtGame) {
              while (!gameView || !gameView->isRunning()) {}
              gameView->addViewFromJSON(json);
            }
            break;

          case OBJECT_DESTROYED:
            if (isAtGame) {
              while (!gameView || !gameView->isRunning()) {}
              gameView->removeViewFromJSON(json);
            }
            break;

          case HP_CHANGE:
            if (isAtGame) dispatchEvent(new HpChangeEvent(json));
            break;

          case AMMO_CHANGE:
            if (isAtGame) dispatchEvent(new AmmoChangeEvent(json));
            break;

          case LIFE_CHANGE:
            if (isAtGame) dispatchEvent(new LifeChangeEvent(json));
            break;
        }
      }
    } catch (const std::exception& e) {
      std::cout << "Exception caught in Receiver thread" << std::endl;
      std::cout << e.what() << std::endl;
    }

  }

public:
  ReceiverThread(Looper *handlerLooper = NULL) : handlerLooper(handlerLooper) { }
  ~ReceiverThread() {
  };

  void setListener(ReceiverContract *listener) {
    this->listener = listener;
  }

  void setSocket(Socket *socket) {
    this->socket = socket;
  }

  void setGame(GameView *view) {
    gameView = view;
  }
};

#endif
