#ifndef CLIENT_EVENTS_CLIENT_FLOWEVENT_H_
#define CLIENT_EVENTS_CLIENT_FLOWEVENT_H_

#include "../../../../Constants.h"
#include "../../../concurrent/client_Event.h"
#include "../../../concurrent/client_Looper.h"

/*
If time is on our side let it implement a data holder that can have information
*/
class FlowEvent : public Event {
private:
  Flow result;
public:
  FlowEvent(Flow result) : result(result) {}

  ~FlowEvent() { }

  virtual int getId() {
    switch (result) {
      case FLOW_START:
        return EVENT_FLOW_START;
      case FLOW_LOBBY:
        return EVENT_FLOW_LOBBY;
      case FLOW_GAME:
        return EVENT_FLOW_GAME;
      default:
        return EVENT_NON_EXISTENT;
    }
  }
};

#endif
