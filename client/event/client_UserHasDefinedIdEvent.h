#ifndef CLIENT_USERHASDEFINEDIDEVENT_H_
#define CLIENT_USERHASDEFINEDIDEVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"
#include "../controller/client_KeyMap.h"

class UserHasDefinedIdEvent : public Event {
private:
  unsigned int userId;

public:
  UserHasDefinedIdEvent(std::string json);

  virtual ~UserHasDefinedIdEvent();

  virtual int getId() ;

  int getUserId();

};

#endif
