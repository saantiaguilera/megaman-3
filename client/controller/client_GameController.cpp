#include <SDL2pp/SDL2pp.hh>

#include "../../common/common_MapConstants.h"
#include "../../common/common_MapViewParser.h"
#include "../../common/common_MapView.h"
#include "../../common/common_Point.h"

#include "../view/game_engine/client_AnimatedView.h"

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
#include "../event/client_UserHasDefinedIdEvent.h"

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
  view->setMyOwnViewMovementListener(this);
}

bool GameController::shouldSendKeyMap(int keyMap) {
  AnimatedView *myView = view->getMyView();
  Point massCenter = view->getMassCenter();
  int delta;

  if (myView == NULL) return false;

  switch (keyMap) {
    case KEY_LEFT:
      delta = myView->getX() - massCenter.getX() - TERRAIN_TILE_SIZE;
      return delta > -SCREEN_SIZE_WIDTH / 2;
    case KEY_RIGHT:
      delta = TERRAIN_TILE_SIZE + myView->getX() - massCenter.getX();
      return delta < SCREEN_SIZE_WIDTH / 2;
    case KEY_JUMP:
      delta = myView->getY() - massCenter.getY() - TERRAIN_TILE_SIZE;
      return delta > -SCREEN_SIZE_HEIGHT / 2;
    case KEY_DOWN:
      delta = TERRAIN_TILE_SIZE + myView->getY() - massCenter.getY();
      return delta < SCREEN_SIZE_HEIGHT / 2;
    default:
      return true;
  }
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
        view->onBarChange(BAR_AMMO, dynamic_cast<GaugeChangeEvent*>(event)->getAmount());
        break;

      case EVENT_HP_CHANGE:
        view->onBarChange(BAR_HP, dynamic_cast<GaugeChangeEvent*>(event)->getAmount());
        break;

      case EVENT_LIFE_CHANGE:
        view->onBarChange(BAR_LIFE, dynamic_cast<GaugeChangeEvent*>(event)->getAmount());
        break;

      case EVENT_USER_HAS_ID:
        view->setMyId(dynamic_cast<UserHasDefinedIdEvent*>(event)->getUserId());
        break;

      default:
        return false;
    }

    return true;
  } else return false;
}

void GameController::setFramesPerSecond(int fps) {
  view->setFramesPerSecond(fps);
}

void GameController::onViewMoved() {
  bool changed = false;

  if (keyMap.isLeft() && !shouldSendKeyMap(KEY_LEFT)) {
    keyMap.setLeft(false);
    changed = true;
  }

  if (keyMap.isRight() && !shouldSendKeyMap(KEY_RIGHT)) {
    keyMap.setRight(false);
    changed = true;
  }

  if (keyMap.isJumping() && !shouldSendKeyMap(KEY_JUMP)) {
    keyMap.setJumping(false);
    changed = true;
  }

  if (keyMap.isDown() && !shouldSendKeyMap(KEY_DOWN)) {
    keyMap.setDown(false);
    changed = true;
  }

  if (changed) {
    Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
    getContext()->onMessageReceived();
  }
}

//https://git.gnome.org/browse/gtk+/tree/gdk/gdkkeysyms.h
bool GameController::onKeyPressEvent(GdkEventKey *gdkEvent) {
  bool notify = true;

  switch (gdkEvent->keyval) {
    case KEY_LEFT:
      if ((keyMap.isLeft() != (gdkEvent->type == GDK_KEY_PRESS)) && shouldSendKeyMap(KEY_LEFT)) {
        keyMap.setLeft(gdkEvent->type == GDK_KEY_PRESS);
        Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      } else notify = false;
      break;

    case KEY_RIGHT:
      if ((keyMap.isRight() != (gdkEvent->type == GDK_KEY_PRESS)) && shouldSendKeyMap(KEY_RIGHT)) {
        keyMap.setRight(gdkEvent->type == GDK_KEY_PRESS);
        Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      } else notify = false;
      break;

    case KEY_DOWN:
    if ((keyMap.isDown() != (gdkEvent->type == GDK_KEY_PRESS)) && shouldSendKeyMap(KEY_DOWN)) {
        keyMap.setDown(gdkEvent->type == GDK_KEY_PRESS);
        Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      } else notify = false;
      break;

    case KEY_JUMP:
      if ((keyMap.isJumping() != (gdkEvent->type == GDK_KEY_PRESS)) && shouldSendKeyMap(KEY_JUMP)) {
        keyMap.setJumping(gdkEvent->type == GDK_KEY_PRESS);
        Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      } else notify = false;
      break;

    case KEY_SHOOT:
      if (keyMap.isShooting() != (gdkEvent->type == GDK_KEY_PRESS)) {
        keyMap.setShooting(gdkEvent->type == GDK_KEY_PRESS);
        Looper::getMainLooper().put(new SendKeyMapEvent(keyMap));
      } else notify = false;
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

    case KEY_WEAPON_6:
      if (gdkEvent->type == GDK_KEY_PRESS)
        Looper::getMainLooper().put(new SendChangeWeaponEvent(Weapon6));
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
