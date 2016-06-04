#ifndef CLIENT_EVENTS_CLIENT_SENDERTHREAD_H_
#define CLIENT_EVENTS_CLIENT_SENDERTHREAD_H_

#include <iostream>
#include "../../../common/common_Socket.h"
#include "../../concurrent/client_Looper.h"
#include "../../../common/common_Thread.h"
#include "../../concurrent/client_Event.h"
#include "../../event/client_StartMapEvent.h"

#include "event/client_SendKeyMapEvent.h"

#include <string>
#include <unistd.h>

class SenderThread : public Thread {
private:
  Looper *handlerLooper;
  Socket *socket;

  std::string name;

protected:
  virtual void run() {
    std::cout << "Senderthread, client name is " << name << std::endl;

    while (socket && socket->isActive()) {
      Event *event = NULL;
      while ((event = handlerLooper->get()) != NULL) {
        switch (event->getId()) {
          case EVENT_SEND_KEY_MAP:
            std::cout << dynamic_cast<SendKeyMapEvent*>(event)->getKeyMap().toString() << std::endl;
            break;

          case EVENT_START_GAME:
            std::cout << "start game with ";
            std::cout << dynamic_cast<StartMapEvent*>(event)->getMapId() << std::endl;
            break;

          default:
            std::cout << "Event not recognized by sender thread..." << std::endl;
        }

        handlerLooper->pop();
      }
    }

    std::cout << "SenderThread::finished running" << std::endl;
  }

public:
  SenderThread(Looper *handlerLooper) : handlerLooper(handlerLooper) { }
  ~SenderThread() {
  };

  void setClientName(std::string name) {
    if (name.length() == 0)
      this->name = "Undefined player";
    else this->name = name;
  }

  void setSocket(Socket *socket) {
    this->socket = socket;
  }
};

#endif
