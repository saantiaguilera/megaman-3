#include "../../Constants.h"
#include "../../common/rapidjson/document.h"

#include "client_LifeChangeEvent.h"

LifeChangeEvent::LifeChangeEvent(std::string json) : GaugeChangeEvent() {
  rapidjson::Document document;
  document.Parse(json.c_str());

  amount = document["life"].GetInt();
}

LifeChangeEvent::~LifeChangeEvent() {

}

int LifeChangeEvent::getId() {
  return EVENT_LIFE_CHANGE;
}
