#ifndef CLIENT_AMMOCHANGEEVENT_H_
#define CLIENT_AMMOCHANGEEVENT_H_

#include "client_GaugeChangeEvent.h"

class AmmoChangeEvent : public GaugeChangeEvent {
private:
  bool special = false;

public:
  AmmoChangeEvent(std::string json);

  virtual ~AmmoChangeEvent();

  bool isSpecial();

  virtual int getId();

};

#endif
