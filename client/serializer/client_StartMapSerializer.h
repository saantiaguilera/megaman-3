#ifndef CLIENT_STARTMAPSERIALIZER_H_
#define CLIENT_STARTMAPSERIALIZER_H_

#include <sstream>
#include <string>
#include "../../common/common_Serializer.h"
#include "../controller/client_KeyMap.h"
#include "../../common/common_MessageProtocol.h"

class StartMapSerializer : public Serializer {
private:
  int mapId;

protected:
  virtual void serialize() {
    std::stringstream ss;
    ss << mapId;

    serialized = ss.str();
  }

public:
  StartMapSerializer(int mapId) : Serializer(), mapId(mapId) {
    messageCode = START_GAME;
    serialize();
  }

  ~StartMapSerializer() {
  }



};

#endif
