#ifndef CLIENT_EVENTS_CLIENT_RECEIVERTHREAD_H_
#define CLIENT_EVENTS_CLIENT_RECEIVERTHREAD_H_

#include <iostream>
#include <exception>

#include "../../../common/common_Socket.h"
#include "../../concurrent/client_Looper.h"
#include "../../../common/common_Thread.h"
#include "../../concurrent/client_Event.h"

#include "../../event/client_DisconnectedPlayerEvent.h"
#include "../../event/client_NewPlayerEvent.h"
#include "../../event/client_ConnectionEvent.h"
#include "../../event/client_FlowEvent.h"
#include "../../event/client_ReceivedMapEvent.h"

#include "../../view/client_GameView.h"

#include "client_ReceiverContract.h"
#include "../../../common/common_MessageProtocol.h"

#include <unistd.h>

class ReceiverThread : public Thread {
private:
  ReceiverContract *listener;
  Looper *handlerLooper;
  Socket *socket;

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
    dispatchEvent(new FlowEvent(FLOW_LOBBY));

    try {
      while (socket && socket->isActive()) {
        //Well, run should only have this while and everything should happen from server data
        // Receive message code
        int messageCode;
        int result = socket->receive((char*) &messageCode, sizeof(int));

        if (result <= 0)
          throw std::exception();

        messageCode = ntohl(messageCode);

        unsigned int messageLength;
        // Receive message length
        result = socket->receive((char*) &messageLength, sizeof(unsigned int));

        if (result <= 0)
          throw std::exception();

        messageLength = ntohl(messageLength);

        std::string json;
        char* buffer = new char[messageLength + 1];
        buffer[messageLength] = 0;
        memset(&buffer[0], 0, sizeof(*buffer));
        result = socket->receive(&buffer[0], messageLength);

        if (result <= 0)
          throw std::exception();

        json += buffer;

        std::cout << "Received::id= " << messageCode << " data=" << json << std::endl;
        switch (messageCode) {
          //Do something
          case NEW_PLAYER:
            dispatchEvent(new NewPlayerEvent(json));
            break;

          case DISCONNECTED_PLAYER:
            dispatchEvent(new DisconnectedPlayerEvent(json));
            break;

          case START_GAME:
            dispatchEvent(new FlowEvent(FLOW_GAME));
            dispatchEvent(new ReceivedMapEvent(json));
            break;

          case UPDATE_MOVEMENTS:
            GameView::moveViewFromJSON(json);
            break;

          case OBJECT_CREATED:
            GameView::addViewFromJSON(json);
            break;

          case OBJECT_DESTROYED:
            GameView::removeViewFromJSON(json);
        }
      }
    } catch (const std::exception& e) {
      //TODO DO SOMETHING
    }

    std::cout << "ReceiverThread::finished running" << std::endl;
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
};

#endif
