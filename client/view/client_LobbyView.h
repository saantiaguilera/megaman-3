#ifndef CLIENT_LOBBYVIEW_H_
#define CLIENT_LOBBYVIEW_H_

#include <gtkmm.h>

class LobbyView : public Gtk::Window {
public:
  LobbyView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
  virtual ~LobbyView();
};

#endif
