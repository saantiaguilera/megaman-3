/*
Masomenos:


#Lo va a construir el MainScreenController cuando apretas enter sobre la IP.
#Lo joinea el MainScreenController en su destructor (si el trhread es !=NULL)
#que esto va a ocurrir cuando se salga del loop infinito del app->run(w);
constructor(Lista de suscriptores a eventos, ip, port) {
- me guardo la lista
- me connecto con ip port
- dispatcheo evento de que tal me fue (el evento no va a ser mas que un
data model con algun switch para diferenciarlos en el suscriptor)
}

--El socket lo clavo a recibir para siempre?? --
void onReceive() {
- intento parsear alguna respuesta coherente
- dispatcheo un evento de eso
}
*/

#ifndef CLIENT_EVENTS_CLIENT_CONNECTIONTHREAD_H_
#define CLIENT_EVENTS_CLIENT_CONNECTIONTHREAD_H_

#include <iostream>
#include "../../concurrent/client_Looper.h"
#include "../../../common/common_ConcurrentList.h"
#include "../../../common/common_Thread.h"
#include "../../concurrent/client_Event.h"

#include "event/client_SendKeyMapEvent.h"
#include "event/client_ConnectionEvent.h"
#include "event/client_FlowEvent.h"

#include <unistd.h>

class ReceiverContract {
public:
  virtual ~ReceiverContract() {};
  virtual void onDataReceived() = 0;
};

class ConnectionThread : public Thread {
private:
  ReceiverContract *listener;
  Looper *handlerLooper;

  void dispatchEvent(Event *event) {
    Looper::getMainLooper().put(event);
    listener->onDataReceived();
  }

protected:
  virtual void run() {
    //Connect to the socket (idk ask the params in the constructor ? ip and port i mean)
    usleep(1000 * 1000 * 3); //1000 micro * 1000 millis * 3 secs.

    //TODO APPEND AN EVENT. This event should be more solid. Like
    /*
    If REUSLT_eRROR -> you can append and exception
    If OK -> append data (like isAdmin?)
    */
    dispatchEvent(new ConnectionEvent(RESULT_OK));

    bool hardcode = true;
    //Suppose we have already connected
    while (hardcode) {//while (connected)
      usleep(1000 * 1000 * 2); //1000 micro * 1000 millis * 2 secs.
      /**Start receiving ALL DA DATAH' and for every
       * DATAH' chunk wrap it up and send it
       */
      dispatchEvent(new FlowEvent(FLOW_LOBBY));

      //TODO YOU SHOULD CONSIDER YOU CAN BE DA ADMIN
      /**
      * Here always before calling the recv() we should fetch from another looper incoming events
      * Because maybe our admin decided to "start the game" and we need somehow to know that.
      * We will achieve this by being able to fork loopers (fuck, thats gonna be hard).
      * GOOGLE HALP DO THE LOOPER CLAS FOR C++
      */
      //Imagine you have also already downloaded the map

      usleep(1000 * 1000 * 2); //1000 micro * 1000 millis * 2 secs.

      dispatchEvent(new FlowEvent(FLOW_GAME));

      bool looping = true;
      while (looping) {
        Event *event = NULL;
        while ((event = handlerLooper->get()) != NULL) {
          switch (event->getId()) {
            case EVENT_SEND_KEY_MAP:
              std::cout << dynamic_cast<SendKeyMapEvent*>(event)->getKeyMap().toString() << std::endl;
              break;

            case EVENT_QUIT:
              looping = false;
              hardcode = false;
              break;

            default:
              std::cout << "Event not recognized by connection thread..." << std::endl;

          }

          handlerLooper->pop();
        }
      }
    }

    std::cout << "ConnectionThread::finished running" << std::endl;
  }

public:
  ConnectionThread(ReceiverContract *listener, Looper *handlerLooper) : listener(listener), handlerLooper(handlerLooper) { }
  ~ConnectionThread() {
  };
};

#endif
