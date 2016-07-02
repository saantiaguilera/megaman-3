#ifndef CLIENT_EVENTS_CLIENT_SENDERTHREAD_H_
#define CLIENT_EVENTS_CLIENT_SENDERTHREAD_H_

#include <iostream>

#include "../../../common/common_Socket.h"
#include "../../../common/common_Thread.h"

#include "../../concurrent/client_Looper.h"
#include "../../concurrent/client_Event.h"

#include "../../../common/common_MessageProtocol.h"

#include "../../event/client_StartMapEvent.h"
#include "../../event/client_SendKeyMapEvent.h"
#include "../../event/client_SendChangeWeaponEvent.h"

#include "../../../common/common_Serializer.h"
#include "../../serializer/client_KeyMapSerializer.h"
#include "../../serializer/client_PlayerConnectedSerializer.h"
#include "../../serializer/client_StartMapSerializer.h"
#include "../../serializer/client_ChangeWeaponSerializer.h"

#include <string>
#include <unistd.h>

class SenderThread : public Thread {
private:
  Looper *handlerLooper;
  Socket *socket;

  std::string name;

protected:
  void send(Serializer *serializer) {
    int code = htonl(serializer->getMessageCode());
    socket->send((char*) &code, sizeof(int));

    int length = htonl(serializer->getMessageLength());
    socket->send((char*) &length, sizeof(length));

    socket->send((char*) serializer->getSerialized().c_str(), serializer->getMessageLength());
  }

  virtual void run() {
    bool stop = false;
    Serializer *serializer = NULL;

    if (socket && socket->isActive()) {
      serializer = new PlayerConnectedSerializer(name);
      send(serializer);

      delete serializer;
      serializer = NULL;
    }

    while (!stop) {
      Event *event = NULL;
      while (!stop && (event = handlerLooper->get()) != NULL) {
        switch (event->getId()) {
          case EVENT_SEND_KEY_MAP:
            serializer = new KeyMapSerializer(dynamic_cast<SendKeyMapEvent*>(event)->getKeyMap());
            break;

          case EVENT_SEND_CHANGE_WEAPON:
            serializer = new ChangeWeaponSerializer(dynamic_cast<SendChangeWeaponEvent*>(event)->getWeaponType());
            break;

          case EVENT_START_GAME:
            serializer = new StartMapSerializer(dynamic_cast<StartMapEvent*>(event)->getMapId());
            break;

          case EVENT_STOP:
            stop = true;
            break;
        }

        if (serializer) {
          send(serializer);
          delete serializer;
          serializer = NULL;
        }

        handlerLooper->pop();
      }
    }
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
