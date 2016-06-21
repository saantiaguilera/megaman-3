#include <iostream>

#include "../event/client_StartMapEvent.h"
#include "../concurrent/client_Looper.h"
#include "client_LobbyController.h"
#include "../event/client_DisconnectedPlayerEvent.h"
#include "../event/client_NewPlayerEvent.h"

#define PATH_LOBBY_LAYOUT "res/layout/client_lobby.glade"
#define PATH_LOBBY_ROOT_VIEW "client_lobby_root_view"

bool LobbyController::onMessageReceived() {
  Event *event = Looper::getMainLooper().get();

  if (event) {
    switch (event->getId()) {
      //Do stuff
      case EVENT_PLAYER_CONNECTED:
        view->addEntry(dynamic_cast<NewPlayerEvent*>(event)->getName() + " has connected.");
        break;

      case EVENT_PLAYER_DISCONNECTED:
        view->addEntry(dynamic_cast<DisconnectedPlayerEvent*>(event)->getName() + " has disconnected.");
        break;

      default:
        return false;
    }

    return true;
  } else return false;
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
    return;
  } catch(const Glib::MarkupError& ex) {
    return;
  } catch(const Gtk::BuilderError& ex) {
    return;
  }

  refBuilder->get_widget_derived(PATH_LOBBY_ROOT_VIEW, view);

  view->setListener(this);
}

void LobbyController::onMapStart(int mapId) {
  Looper::getMainLooper().put(new StartMapEvent(mapId));
  getContext()->onMessageReceived();
}
