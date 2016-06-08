#include "../../common/rapidjson/document.h"
#include "../../Constants.h"

#include "client_HpChangeEvent.h"

HpChangeEvent::HpChangeEvent(std::string json) : GaugeChangeEvent() {
  rapidjson::Document document;
  document.Parse(json.c_str());

  amount = document["hp"].GetUint();
}

HpChangeEvent::~HpChangeEvent() {

}

int HpChangeEvent::getId() {
  return EVENT_HP_CHANGE;
}
