#ifndef CLIENT_EVENTS_STOPLOOPEREVENT_H_
#define CLIENT_EVENTS_STOPLOOPEREVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"

class StopLooperEvent : public Event {
public:
  StopLooperEvent() {}

  ~StopLooperEvent() { }

  virtual int getId() {
    return EVENT_STOP;
  }

};

#endif
