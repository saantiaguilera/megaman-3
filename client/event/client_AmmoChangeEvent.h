#ifndef CLIENT_AMMOCHANGEEVENT_H_
#define CLIENT_AMMOCHANGEEVENT_H_

#include "client_GaugeChangeEvent.h"

class AmmoChangeEvent : public GaugeChangeEvent {
public:
  AmmoChangeEvent(std::string json);

  virtual ~AmmoChangeEvent();

  virtual int getId();

};

#endif
