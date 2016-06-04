#ifndef CLIENT_DISCONNECTEDPLAYEREVENT_H_
#define CLIENT_DISCONNECTEDPLAYEREVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"
#include <string>

class DisconnectedPlayerEvent : public Event {
private:
  std::string name;

public:
  DisconnectedPlayerEvent(std::string name) : name(name) {
  }

  virtual ~DisconnectedPlayerEvent() {

  }

  virtual int getId() {
    return EVENT_PLAYER_DISCONNECTED;
  }

  std::string getName() {
    return name;
  }

};

#endif
