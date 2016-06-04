#ifndef CLIENT_EVENTS_CLIENT_SENDERTHREAD_H_
#define CLIENT_EVENTS_CLIENT_SENDERTHREAD_H_

#include <iostream>
#include "../../../common/common_Socket.h"
#include "../../concurrent/client_Looper.h"
#include "../../../common/common_Thread.h"
#include "../../concurrent/client_Event.h"
#include "../../event/client_StartMapEvent.h"
#include "../../../common/common_MessageProtocol.h"
#include "../../event/client_SendKeyMapEvent.h"

#include "../../../common/common_Serializer.h"
#include "../../serializer/client_KeyMapSerializer.h"
#include "../../serializer/client_PlayerConnectedSerializer.h"
#include "../../serializer/client_StartMapSerializer.h"

#include <string>
#include <unistd.h>

class SenderThread : public Thread {
private:
  Looper *handlerLooper;
  Socket *socket;

  std::string name;

protected:
  void send(Serializer *serializer) {
    std::cout << "Sending::id: " << serializer->getMessageCode() << " data: " << serializer->getSerialized() << std::endl;

    int code = htonl(serializer->getMessageCode());
    socket->send((char*) &code, sizeof(int));

    int length = htonl(serializer->getMessageLength());
    socket->send((char*) &length, sizeof(length));

    socket->send((char*) serializer->getSerialized().c_str(), serializer->getMessageLength());
  }

  virtual void run() {
    Serializer *serializer = NULL;

    if (socket && socket->isActive()) {
      serializer = new PlayerConnectedSerializer(name);
      send(serializer);

      delete serializer;
    }

    while (socket && socket->isActive()) {
      Event *event = NULL;
      while ((event = handlerLooper->get()) != NULL) {
        switch (event->getId()) {
          case EVENT_SEND_KEY_MAP:
            serializer = new KeyMapSerializer(dynamic_cast<SendKeyMapEvent*>(event)->getKeyMap());
            break;

          case EVENT_START_GAME:
            serializer = new StartMapSerializer(dynamic_cast<StartMapEvent*>(event)->getMapId());
            break;

          default:
            std::cout << "Event not recognized by sender thread..." << std::endl;
        }

        if (serializer) {
          send(serializer);
          delete serializer;
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
