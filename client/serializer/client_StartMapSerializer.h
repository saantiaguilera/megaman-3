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
public:
  StartMapSerializer(int mapId) : Serializer(), mapId(mapId) {
  }

  ~StartMapSerializer() {
  }

  virtual void serialize() {
    std::stringstream ss;
    ss << mapId;

    serialized = ss.str();

    messageLength = serialized.length();
  }

};

#endif
