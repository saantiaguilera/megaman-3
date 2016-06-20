#ifndef CLIENT_LOBBYVIEW_H_
#define CLIENT_LOBBYVIEW_H_

#include <gtkmm.h>

class LobbyViewListener {
public:
  virtual void onMapStart(int mapId) = 0;
  virtual ~LobbyViewListener() {}
};

class LobbyView : public Gtk::Window {
private:
  Gtk::Button *mapOneButton;
  Gtk::Button *mapTwoButton;
  Gtk::Button *mapThreeButton;
  Gtk::Button *mapFourButton;
  Gtk::Button *mapFiveButton;
  Gtk::ListBox *listView;

  LobbyViewListener *listener = NULL;

  void onMapStart(int mapId);

public:
  LobbyView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
  virtual ~LobbyView();

  void addEntry(std::string entry);
  void setListener(LobbyViewListener *listenr);
};

#endif
