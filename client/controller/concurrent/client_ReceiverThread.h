#ifndef CLIENT_EVENTS_CLIENT_RECEIVERTHREAD_H_
#define CLIENT_EVENTS_CLIENT_RECEIVERTHREAD_H_

#include <iostream>
#include "../../../common/common_Socket.h"
#include "../../concurrent/client_Looper.h"
#include "../../../common/common_Thread.h"
#include "../../concurrent/client_Event.h"

#include "event/client_ConnectionEvent.h"
#include "event/client_FlowEvent.h"
#include "client_ReceiverContract.h"

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

    usleep(1000 * 1000 * 2); //1000 micro * 1000 millis * 2 secs.

    dispatchEvent(new FlowEvent(FLOW_GAME));

    while (socket && socket->isActive()) {
      //Well, run should only have this while and everything should happen from server data
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
