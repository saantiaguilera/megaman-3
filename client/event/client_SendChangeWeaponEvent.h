#ifndef CLIENT_SENDCHANGEWEAPONEVENT_H_
#define CLIENT_SENDCHANGEWEAPONEVENT_H_

#include "../../Constants.h"
#include "../concurrent/client_Event.h"
#include "../controller/client_KeyMap.h"
#include "../../common/common_MapConstants.h"

class SendChangeWeaponEvent : public Event {
private:
  WeaponType weapon;

public:
  SendChangeWeaponEvent(WeaponType weapon) : weapon(weapon) {
  }

  virtual ~SendChangeWeaponEvent() {

  }

  virtual int getId() {
    return EVENT_SEND_CHANGE_WEAPON;
  }

  WeaponType getWeaponType() {
    return weapon;
  }

};

#endif
