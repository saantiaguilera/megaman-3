#ifndef CLIENT_CLIENT_EVENT_H_
#define CLIENT_CLIENT_EVENT_H_

class Event {
public:
  virtual ~Event() {};

  virtual int getId() = 0;
};

#endif
