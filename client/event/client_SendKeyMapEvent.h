#ifndef CLIENT_SENDKEYMAPEVENT_H_
#define CLIENT_SENDKEYMAPEVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"
#include "../controller/client_KeyMap.h"

class SendKeyMapEvent : public Event {
private:
  KeyMap map;

public:
  SendKeyMapEvent(KeyMap map) : map(map) {

  }

  virtual ~SendKeyMapEvent() {

  }

  virtual int getId() {
    return EVENT_SEND_KEY_MAP;
  }

  KeyMap getKeyMap() {
    return map;
  }
};

#endif
