#ifndef CLIENT_QUITEVENT_H_
#define CLIENT_QUITEVENT_H_

class QuitEvent : public Event {
public:
  QuitEvent() {

  }

  virtual ~QuitEvent() {

  }

  virtual int getId() {
    return EVENT_QUIT;
  }
};

#endif
