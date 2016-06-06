#ifndef CLIENT_CHANGEWEAPONSERIALIZER_H_
#define CLIENT_CHANGEWEAPONSERIALIZER_H_

#include <sstream>
#include <string>
#include "../../common/common_Serializer.h"
#include "../controller/client_KeyMap.h"
#include "../../common/common_MessageProtocol.h"
#include "../../common/common_MapConstants.h"

class ChangeWeaponSerializer : public Serializer {
private:
  WeaponType weaponType;

protected:
  virtual void serialize() {
    std::stringstream ss;
    ss << (int) weaponType;
    serialized = ss.str();
  }

public:
  ChangeWeaponSerializer(WeaponType weaponType) : Serializer(), weaponType(weaponType) {
    messageCode = WEAPON_CHANGE;
    serialize();
  }

  ~ChangeWeaponSerializer() {

  }

};

#endif
