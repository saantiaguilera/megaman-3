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
#include "../event/client_AmmoChangeEvent.h"
#include "../event/client_GaugeChangeEvent.h"
#include "../event/client_HpChangeEvent.h"
#include "../event/client_LifeChangeEvent.h"

#include "client_GameController.h"

#define PATH_LOBBY_LAYOUT "res/layout/client_game_view.glade"
#define PATH_LOBBY_ROOT_VIEW "client_game_view_window"

GameController::~GameController() {
  delete view;
}

/**
 * Create builder, parse xml, delegate inflate responsibility, set callbacks
 */
GameController::GameController(Context *context) : Controller(context), view(nullptr) {
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

      case EVENT_AMMO_CHANGE:
        view->onBarChange(dynamic_cast<AmmoChangeEvent*>(event)->isSpecial() ? BAR_SPECIAL_AMMO : BAR_AMMO, dynamic_cast<GaugeChangeEvent*>(event)->getAmount());
        break;

      case EVENT_HP_CHANGE:
        view->onBarChange(BAR_HP, dynamic_cast<GaugeChangeEvent*>(event)->getAmount());
        break;

      case EVENT_LIFE_CHANGE:
        view->onBarChange(BAR_LIFE, dynamic_cast<GaugeChangeEvent*>(event)->getAmount());
        break;

      default:
        return false;
    }

    return true;
  } else return false;
}

//https://git.gnome.org/browse/gtk+/tree/gdk/gdkkeysyms.h
bool GameController::onKeyPressEvent(GdkEventKey *gdkEvent) {
  bool notify = true;

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
      if (gdkEvent->type == GDK_KEY_PRESS)
        Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon1));
      else notify = false;
      break;

    case KEY_WEAPON_2:
      if (gdkEvent->type == GDK_KEY_PRESS)
        Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon2));
      else notify = false;
      break;

    case KEY_WEAPON_3:
      if (gdkEvent->type == GDK_KEY_PRESS)
        Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon3));
      else notify = false;
      break;

    case KEY_WEAPON_4:
      if (gdkEvent->type == GDK_KEY_PRESS)
        Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon4));
      else notify = false;
      break;

    case KEY_WEAPON_5:
      if (gdkEvent->type == GDK_KEY_PRESS)
        Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon5));
      else notify = false;
      break;

    default:
      notify = false;
  }

  if (notify) {
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
