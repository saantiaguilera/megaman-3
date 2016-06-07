
#include "../../Constants.h"
#include "../../common/rapidjson/document.h"

#include "client_AmmoChangeEvent.h"

AmmoChangeEvent::AmmoChangeEvent(std::string json) : GaugeChangeEvent() {
  rapidjson::Document document;
  document.Parse(json.c_str());

  amount = document["ammo"].GetInt();
  special = document["special"].GetBool();
}

AmmoChangeEvent::~AmmoChangeEvent() {

}

bool AmmoChangeEvent::isSpecial() {
  return special;
}

int AmmoChangeEvent::getId() {
  return EVENT_AMMO_CHANGE;
}
