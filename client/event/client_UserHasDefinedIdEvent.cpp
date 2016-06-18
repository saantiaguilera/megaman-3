#include "../../common/rapidjson/document.h"
#include "../../Constants.h"

#include "client_UserHasDefinedIdEvent.h"

UserHasDefinedIdEvent::UserHasDefinedIdEvent(std::string json) : Event() {
  rapidjson::Document document;
  document.Parse(json.c_str());

  userId = document["your_id"].GetUint();
}

UserHasDefinedIdEvent::~UserHasDefinedIdEvent() {

}

int UserHasDefinedIdEvent::getId() {
  return EVENT_USER_HAS_ID;
}

int UserHasDefinedIdEvent::getUserId() {
  return userId;
}
