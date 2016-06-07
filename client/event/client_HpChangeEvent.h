#ifndef CLIENT_HPCHANGEEVENT_H_
#define CLIENT_HPCHANGEEVENT_H_

#include "client_GaugeChangeEvent.h"

class HpChangeEvent : public GaugeChangeEvent {
public:
  HpChangeEvent(std::string json);

  virtual ~HpChangeEvent();

  virtual int getId();

};

#endif
