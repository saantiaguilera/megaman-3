#ifndef CLIENT_LIFECHANGEEVENT_H_
#define CLIENT_LIFECHANGEEVENT_H_

#include "client_GaugeChangeEvent.h"

class LifeChangeEvent : public GaugeChangeEvent {
public:
  LifeChangeEvent(std::string json);

  virtual ~LifeChangeEvent();

  virtual int getId();

};

#endif
