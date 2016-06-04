#include <iostream>

#include "../event/client_StartMapEvent.h"
#include "../concurrent/client_Looper.h"
#include "client_LobbyController.h"

#define PATH_LOBBY_LAYOUT "res/layout/client_lobby.glade"
#define PATH_LOBBY_ROOT_VIEW "client_lobby_root_view"

bool LobbyController::onMessageReceived() {
  return true;
}

Gtk::Window * LobbyController::getView() { return view; }

void LobbyController::setVisibility(bool visible) {
  if (!view)
    return;

  if (visible)
    view->show();
  else view->hide();
}

LobbyController::~LobbyController() {
  delete view;
}

LobbyController::LobbyController(Context *context) : Controller(context), view(nullptr) {
  auto refBuilder = Gtk::Builder::create();

  try {
    refBuilder->add_from_file(PATH_LOBBY_LAYOUT);
  } catch(const Glib::FileError& ex) {
    std::cout << "FileError: " << ex.what() << std::endl;
    return;
  } catch(const Glib::MarkupError& ex) {
    std::cout << "MarkupError: " << ex.what() << std::endl;
    return;
  } catch(const Gtk::BuilderError& ex) {
    std::cout << "BuilderError: " << ex.what() << std::endl;
    return;
  }

  refBuilder->get_widget_derived(PATH_LOBBY_ROOT_VIEW, view);

  view->setListener(this);
}

void LobbyController::onMapStart(int mapId) {
  Looper::getMainLooper().put(new StartMapEvent(mapId));
  getContext()->onMessageReceived();
}
