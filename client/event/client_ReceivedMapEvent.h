#ifndef CLIENT_RECEIVEDMAPEVENT_H_
#define CLIENT_RECEIVEDMAPEVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"
#include "../controller/client_KeyMap.h"

class ReceivedMapEvent : public Event {
private:
  std::string mapJson;

public:
  ReceivedMapEvent(std::string mapJson) : mapJson(mapJson) {
    std::cout << "ReceivedMapEvent Map JSON:: " << mapJson << std::endl;
  }

  virtual ~ReceivedMapEvent() {

  }

  virtual int getId() {
    return EVENT_RECEIVED_MAP;
  }

  std::string getMapJSON() {
    return mapJson;
  }

};

#endif
