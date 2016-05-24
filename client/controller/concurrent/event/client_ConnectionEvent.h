#ifndef CLIENT_EVENTS_CLIENT_CONNECTIONEVENT_H_
#define CLIENT_EVENTS_CLIENT_CONNECTIONEVENT_H_

#include "../../../../Constants.h"
#include "../../../concurrent/client_Event.h"

/*
If time is on our side let it implement a data holder that can have information about the error eg
*/
class ConnectionEvent : public Event {
private:
  ConnectionResult result;
public:
  ConnectionEvent(ConnectionResult result) : result(result) {}

  ~ConnectionEvent() { }

  virtual int getId() {
    switch (result) {
      case RESULT_OK:
        return EVENT_CONNECTION_ACCEPTED;
      case RESULT_ERROR:
        return EVENT_CONNECTION_REFUSED;
      default:
        return EVENT_NON_EXISTENT;
    }
  }
};

#endif
