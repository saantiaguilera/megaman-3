#include <iostream>
#include <string>
#include "client_LobbyView.h"

#define PATH_LOBBY_MAP_ONE "client_lobby_map_one"
#define PATH_LOBBY_MAP_TWO "client_lobby_map_two"
#define PATH_LOBBY_MAP_THREE "client_lobby_map_three"
#define PATH_LOBBY_MAP_FOUR "client_lobby_map_four"
#define PATH_LOBBY_LIST_VIEW "client_lobby_list_view"

#define ID_MAP_ONE 1
#define ID_MAP_TWO 2
#define ID_MAP_THREE 3
#define ID_MAP_FOUR 4

LobbyView::LobbyView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) :
        Gtk::Window(cobject) {
  refBuilder->get_widget(PATH_LOBBY_MAP_ONE, mapOneButton);
  refBuilder->get_widget(PATH_LOBBY_MAP_TWO, mapTwoButton);
  refBuilder->get_widget(PATH_LOBBY_MAP_THREE, mapThreeButton);
  refBuilder->get_widget(PATH_LOBBY_MAP_FOUR, mapFourButton);
  refBuilder->get_widget(PATH_LOBBY_LIST_VIEW, listView);

  mapOneButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &LobbyView::onMapStart), ID_MAP_ONE));
  mapTwoButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &LobbyView::onMapStart), ID_MAP_TWO));
  mapThreeButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &LobbyView::onMapStart), ID_MAP_THREE));
  mapFourButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &LobbyView::onMapStart), ID_MAP_FOUR));
}

void LobbyView::onMapStart(int mapId) {
  if (listener)
    listener->onMapStart(mapId);
}

void LobbyView::addEntry(std::string entry) {
  Gtk::Label *labelView = new Gtk::Label();
  labelView->set_text(entry);

  listView->append(*labelView);
  listView->show_all();
}

void LobbyView::setListener(LobbyViewListener *listener) {
  this->listener = listener;
}

LobbyView::~LobbyView() {
}
