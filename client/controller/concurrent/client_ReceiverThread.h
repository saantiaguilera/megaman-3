#ifndef CLIENT_EVENTS_CLIENT_RECEIVERTHREAD_H_
#define CLIENT_EVENTS_CLIENT_RECEIVERTHREAD_H_

#include <iostream>
#include "../../../common/common_Socket.h"
#include "../../concurrent/client_Looper.h"
#include "../../../common/common_Thread.h"
#include "../../concurrent/client_Event.h"
#include "../../event/client_DisconnectedPlayerEvent.h"
#include "../../event/client_NewPlayerEvent.h"

#include "event/client_ConnectionEvent.h"
#include "event/client_FlowEvent.h"
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
    usleep(1000 * 1000 * 2);

    dispatchEvent(new FlowEvent(FLOW_LOBBY));

    while (socket && socket->isActive()) {
      //Well, run should only have this while and everything should happen from server data
      // Receive message code
      int messageCode;
      socket->receive((char*) &messageCode, sizeof(int));
      // TODO: Log receive error
      messageCode = ntohl(messageCode);

      unsigned int messageLength;
      // Receive message length
      socket->receive((char*) &messageLength, sizeof(unsigned int));
      // TODO: Log receive error
      messageLength = ntohl(messageLength);

      std::string json;
      // Done workaround of size + 1 to avoid valgrind error
      if (messageLength > 0) {
        char* buffer = new char[messageLength + 1];
        buffer[messageLength] = 0;
        memset(&buffer[0], 0, sizeof(*buffer));
        if (socket->receive(&buffer[0], messageLength) != -1) {
          json += buffer;
        }
      }

      std::cout << "Received::id= " << messageCode << " data=" << json << std::endl;
      switch (messageCode) {
        //Do something
        case NEW_PLAYER:
          dispatchEvent(new NewPlayerEvent(json));
          break;

        case DISCONNECTED_PLAYER:
          dispatchEvent(new DisconnectedPlayerEvent(json));
          break;
      }
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
