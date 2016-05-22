#ifndef SDL_WRAPPER
#define SDL_WRAPPER
#include <SDL2pp/SDL2pp.hh>
#endif

#include <iostream>

#include "client_GameController.h"

GameController::~GameController() {
  delete view;
}

/**
 * Create builder, parse xml, delegate inflate responsibility, set callbacks
 */
GameController::GameController(Context *context) : Controller(context), view(nullptr) {
  view = new GameView();
}

bool GameController::onMessageReceived() {
  return true;
}

Gtk::Window * GameController::getView() { return view; }

void GameController::setVisibility(bool visible) {
  if (!view)
    return;

  if (visible)
    view->show();
  else view->hide();
}
