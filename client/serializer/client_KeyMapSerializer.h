#ifndef CLIENT_KEYMAPSERIALIZER_H_
#define CLIENT_KEYMAPSERIALIZER_H_

#include <sstream>
#include <string>
#include "../../common/common_Serializer.h"
#include "../controller/client_KeyMap.h"
#include "../../common/common_MessageProtocol.h"

class KeyMapSerializer : public Serializer {
private:
  KeyMap keyMap;
public:
  KeyMapSerializer(KeyMap keyMap) : Serializer(), keyMap(keyMap) {
    messageCode = KEY_PRESSED;
  }

  ~KeyMapSerializer() {

  }

  virtual void serialize() {
    std::stringstream ss;
    ss << (int) keyMap.isJumping();
    ss << (int) keyMap.isDown();
    ss << (int) keyMap.isLeft();
    ss << (int) keyMap.isRight();
    ss << (int) keyMap.isShooting();

    serialized = ss.str();

    messageLength = serialized.length();
  }

};

#endif
