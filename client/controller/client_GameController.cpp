#ifndef SDL_WRAPPER
#define SDL_WRAPPER
#include <SDL2pp/SDL2pp.hh>
#endif

#include <iostream>
#include "../concurrent/client_Event.h"
#include "concurrent/event/client_SendKeyMapEvent.h"
#include "concurrent/event/client_QuitEvent.h"
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
  return true;
}

//https://git.gnome.org/browse/gtk+/tree/gdk/gdkkeysyms.h
bool GameController::onKeyPressEvent(GdkEventKey *gdkEvent) {
  Event *dispatchingEvent = NULL;

  //TODO PASS TO A DEFINE ALL THIS GDKKEYS SO I CAN RE MAP THE CONTROLLERS OF THE GAME EASIER
  //TODO REFACTOR DIS
  switch (gdkEvent->keyval) {
    case GDK_KEY_Left:
      keyMap.setLeft(gdkEvent->type == GDK_KEY_PRESS);
      dispatchingEvent = new SendKeyMapEvent(keyMap);
      break;

    case GDK_KEY_Right:
      keyMap.setRight(gdkEvent->type == GDK_KEY_PRESS);
      dispatchingEvent = new SendKeyMapEvent(keyMap);
      break;

    case GDK_KEY_Up:
      keyMap.setUp(gdkEvent->type == GDK_KEY_PRESS);
      dispatchingEvent = new SendKeyMapEvent(keyMap);
      break;

    case GDK_KEY_Down:
      keyMap.setDown(gdkEvent->type == GDK_KEY_PRESS);
      dispatchingEvent = new SendKeyMapEvent(keyMap);
      break;

    case GDK_KEY_s:
      keyMap.setShooting(gdkEvent->type == GDK_KEY_PRESS);
      dispatchingEvent = new SendKeyMapEvent(keyMap);
      break;

    case GDK_KEY_a:
      keyMap.setJumping(gdkEvent->type == GDK_KEY_PRESS);
      dispatchingEvent = new SendKeyMapEvent(keyMap);
      break;

    case GDK_KEY_Escape: //So the user can quit the app ?
      dispatchingEvent = new QuitEvent();
  }

  if (dispatchingEvent) {
    Looper::getMainLooper().put(dispatchingEvent);
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
