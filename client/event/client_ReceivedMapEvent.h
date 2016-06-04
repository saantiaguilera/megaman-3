#ifndef CLIENT_RECEIVEDMAPEVENT_H_
#define CLIENT_RECEIVEDMAPEVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"
#include "../controller/client_KeyMap.h"

class ReceivedMapEvent : public Event {
private:

public:
  ReceivedMapEvent(std::string mapJson) {
    std::cout << "Map JSON:: " << mapJson << std::endl;
  }

  virtual ~ReceivedMapEvent() {

  }

  virtual int getId() {
    return EVENT_RECEIVED_MAP;
  }
};

#endif
