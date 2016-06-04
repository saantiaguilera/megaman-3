#ifndef CLIENT_STARTMAPEVENT_H_
#define CLIENT_STARTMAPEVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"

class StartMapEvent : public Event {
private:
  int mapId;

public:
  StartMapEvent(int mapId) : mapId(mapId) {
  }

  virtual ~StartMapEvent() {

  }

  virtual int getId() {
    return EVENT_START_GAME;
  }

  int getMapId() {
    return mapId;
  }

};

#endif
