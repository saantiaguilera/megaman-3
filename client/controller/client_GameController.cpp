#include <SDL2pp/SDL2pp.hh>

#include "../../common/common_MapConstants.h"
#include "../../common/common_MapViewParser.h"
#include "../../common/common_MapView.h"

#include <iostream>
#include "../concurrent/client_Event.h"
#include "../event/client_SendKeyMapEvent.h"
#include "../event/client_QuitEvent.h"
#include "../event/client_ReceivedMapEvent.h"
#include "../event/client_SendChangeWeaponEvent.h"

#include "client_GameController.h"

GameController::~GameController() {
  delete view;
}

/**
 * Create builder, parse xml, delegate inflate responsibility, set callbacks
 */
GameController::GameController(Context *context) : Controller(context), view(nullptr) {
  view = new GameView();
  view->setKeyPressListener(this);
}

bool GameController::onMessageReceived() {
  Event *event = Looper::getMainLooper().get();

  if (event) {
    MapViewParser *parser;
    MapView *mapView;

    switch (event->getId()) {
      //Do stuff
      case EVENT_RECEIVED_MAP:
        mapView = new MapView();
        parser = new MapViewParser();
        parser->clientMapFromString(mapView, dynamic_cast<ReceivedMapEvent*>(event)->getMapJSON());
        this->view->loadMapFromAsset(mapView);
        delete parser;
        break;

      default:
        return false;
    }

    return true;
  } else return false;
}

//https://git.gnome.org/browse/gtk+/tree/gdk/gdkkeysyms.h
bool GameController::onKeyPressEvent(GdkEventKey *gdkEvent) {
  bool changed = true;

  //TODO PASS TO A DEFINE ALL THIS GDKKEYS SO I CAN RE MAP THE CONTROLLERS OF THE GAME EASIER
  //TODO REFACTOR DIS
  switch (gdkEvent->keyval) {
    case KEY_LEFT:
      keyMap.setLeft(gdkEvent->type == GDK_KEY_PRESS);
      Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      break;

    case KEY_RIGHT:
      keyMap.setRight(gdkEvent->type == GDK_KEY_PRESS);
      Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      break;

    case KEY_DOWN:
      keyMap.setDown(gdkEvent->type == GDK_KEY_PRESS);
      Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      break;

    case KEY_SHOOT:
      keyMap.setShooting(gdkEvent->type == GDK_KEY_PRESS);
      Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      break;

    case KEY_JUMP:
      keyMap.setJumping(gdkEvent->type == GDK_KEY_PRESS);
      Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      break;

    case KEY_WEAPON_1:
      Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon1));
      break;

    case KEY_WEAPON_2:
      Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon2));
      break;

    case KEY_WEAPON_3:
      Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon3));
      break;

    case KEY_WEAPON_4:
      Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon4));
      break;

    case KEY_WEAPON_5:
      Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon5));
      break;

    default:
      changed = false;
  }

  if (changed) {
    getContext()->onMessageReceived();
    return true;
  }

  return false;
}

Gtk::Window * GameController::getView() { return view; }

void GameController::setVisibility(bool visible) {
  if (!view)
    return;

  if (visible)
    view->show();
  else view->hide();
}
