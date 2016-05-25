#ifndef CLIENT_EVENTS_CLIENT_SENDERTHREAD_H_
#define CLIENT_EVENTS_CLIENT_SENDERTHREAD_H_

#include <iostream>
#include "../../../common/common_Socket.h"
#include "../../concurrent/client_Looper.h"
#include "../../../common/common_Thread.h"
#include "../../concurrent/client_Event.h"

#include "event/client_SendKeyMapEvent.h"

#include <unistd.h>

class SenderThread : public Thread {
private:
  Looper *handlerLooper;
  Socket *socket;

protected:
  virtual void run() {
    while (socket && socket->isActive()) {
      Event *event = NULL;
      while ((event = handlerLooper->get()) != NULL) {
        switch (event->getId()) {
          case EVENT_SEND_KEY_MAP:
            std::cout << dynamic_cast<SendKeyMapEvent*>(event)->getKeyMap().toString() << std::endl;
            break;

          default:
            std::cout << "Event not recognized by sender thread..." << std::endl;
        }

        handlerLooper->pop();
      }
    }

    std::cout << "SenderTHread::finished running" << std::endl;
  }

public:
  SenderThread(Looper *handlerLooper) : handlerLooper(handlerLooper) { }
  ~SenderThread() {
  };

  void setSocket(Socket *socket) {
    this->socket = socket;
  }
};

#endif
