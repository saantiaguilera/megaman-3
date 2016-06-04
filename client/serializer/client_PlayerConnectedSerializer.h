#ifndef CLIENT_PLAYERCONNECTEDSERIALIZER_H_
#define CLIENT_PLAYERCONNECTEDSERIALIZER_H_

#include <string>
#include "../../common/common_Serializer.h"
#include "../../common/common_MessageProtocol.h"

class PlayerConnectedSerializer : public Serializer {
private:
  std::string name;

protected:
  virtual void serialize() {
    serialized = name;
  }

public:
  PlayerConnectedSerializer(std::string name) : Serializer(), name(name) {
    messageCode = PLAYER_CONNECTED;
    serialize();
  }

  ~PlayerConnectedSerializer() {

  }

};

#endif
