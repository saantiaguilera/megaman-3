#ifndef CLIENT_CONNECTIONTHREAD_H_
#define CLIENT_CONNECTIONTHREAD_H_


#include <iostream>
#include "../../../common/common_Socket.h"
#include "../../concurrent/client_Looper.h"
#include "../../../common/common_Thread.h"
#include "../../concurrent/client_Event.h"

#include "../../event/client_ConnectionEvent.h"
#include "../../event/client_FlowEvent.h"
#include "client_ReceiverContract.h"

#include <unistd.h>

class ConnectionThread : public Thread {
private:
  ReceiverContract *listener;
  Looper *handlerLooper;
  Socket *socket;
  std::string ip;
  std::string port;

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
    if (socket) {
      //I would love to use my sockets, but (I WONT SAY WHO COFCOFTINCHOCOFCOF makes me use his that I have to cast to char* the things instead of using string)
      socket->build((char*) ip.c_str(), port.c_str());
      int result = socket->connect();

      switch (result) {
        case EXIT_SUCCESS:
          dispatchEvent(new ConnectionEvent(RESULT_OK));
          break;

        default:
          dispatchEvent(new ConnectionEvent(RESULT_ERROR));
      }
    }
  }

public:
  ConnectionThread(Looper *handlerLooper = NULL) : handlerLooper(handlerLooper) { }
  ~ConnectionThread() {
  };

  void setListener(ReceiverContract *listener) {
    this->listener = listener;
  }

  void setSocket(Socket *socket) {
    this->socket = socket;
  }

  void setData(std::string ip, std::string port) {
    this->ip = ip;
    this->port = port;
  }
};

#endif
