#ifndef CLIENT_EVENTS_CLIENT_CREATECONNECTIONEVENT_H_
#define CLIENT_EVENTS_CLIENT_CREATECONNECTIONEVENT_H_

#include "../../../../Constants.h"
#include "../../../concurrent/client_Event.h"
#include "../../../concurrent/client_Looper.h"

/*
If time is on our side let it implement a data holder that can have information about the error eg
*/
class CreateConnectionEvent : public Event {
private:
  std::string ip;
public:
  CreateConnectionEvent(std::string ip) : ip(ip) {}

  ~CreateConnectionEvent() { }

  virtual int getId() {
    return EVENT_CREATE_CONNECTION;
  }

  std::string getIP() {
    return ip;
  }
};

#endif
