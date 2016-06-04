#ifndef CLIENT_KEYMAPSERIALIZER_H_
#define CLIENT_KEYMAPSERIALIZER_H_

#include <string>
#include "../../common/common_Serializer.h"
#include "../controller/client_KeyMap.h"

class KeyMapSerializer : public Serializer {
private:
  KeyMap *keyMap;
public:
  KeyMapSerializer(KeyMap *keyMap) : Serializer(), keyMap(keyMap) {

  }

  ~KeyMapSerializer() {

  }

  virtual void serialize() {
    serialized = (keyMap->isJumping ? "1" : "0") +
              (keyMap->isDown ? "1" : "0") +
              (keyMap->isLeft ? "1" : "0") +
              (keyMap->isRight ? "1" : "0") +
              (keyMap->isShooting ? "1" : "0");
  }

}

#endif
