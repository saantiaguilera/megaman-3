#ifndef CLIENT_GAUGECHANGEEVENT_H_
#define CLIENT_GAUGECHANGEEVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"

class GaugeChangeEvent : public Event {
protected:
  unsigned int amount;

public:
  GaugeChangeEvent() {
  }

  virtual ~GaugeChangeEvent() {

  }

  virtual int getId() = 0;

  unsigned int getAmount() {
    return amount;
  }

};

#endif
