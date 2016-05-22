#include <iostream>

#include "client_LobbyView.h"

LobbyView::LobbyView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) :
        Gtk::Window(cobject) {
}

LobbyView::~LobbyView() {}
