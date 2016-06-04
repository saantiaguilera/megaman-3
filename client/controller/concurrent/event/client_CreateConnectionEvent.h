#ifndef CLIENT_EVENTS_CLIENT_CREATECONNECTIONEVENT_H_
#define CLIENT_EVENTS_CLIENT_CREATECONNECTIONEVENT_H_

#include "../../../../Constants.h"
#include "../../../concurrent/client_Event.h"

/*
If time is on our side let it implement a data holder that can have information about the error eg
*/
class CreateConnectionEvent : public Event {
private:
  std::string ipport;
  std::string name;

public:
  CreateConnectionEvent(std::string ipport, std::string name) : ipport(ipport), name(name) {}

  ~CreateConnectionEvent() { }

  virtual int getId() {
    return EVENT_CREATE_CONNECTION;
  }

  std::string getIPAndPort() {
    return ipport;
  }

  std::string getName() {
    return name;
  }
};

#endif
