#ifndef CLIENT_NEWPLAYEREVENT_H_
#define CLIENT_NEWPLAYEREVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"
#include <string>

class NewPlayerEvent : public Event {
private:
  std::string name;

public:
  NewPlayerEvent(std::string name) : name(name) {
  }

  virtual ~NewPlayerEvent() {

  }

  virtual int getId() {
    return EVENT_PLAYER_CONNECTED;
  }

  std::string getName() {
    return name;
  }

};

#endif
