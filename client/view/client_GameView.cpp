#include <iostream>

#include "client_GameView.h"

#define DRAW_TIME_STEP 16

GameView::GameView() : Gtk::Window() {
 set_size_request(800, 600); //TODO

 socket = manage(new Gtk::Socket());

 add(*socket);
 show_all();
}

GameView::~GameView() {
  delete worldView;
  delete stintv;
  delete renderer;
  delete mainWindow;
  delete sdl;
}

bool GameView::onLoopSDL() {
 try {
   renderer->Clear();

   worldView->draw();
   //stintv->draw();

   renderer->Present();

   return true;
 } catch (std::exception& e) {
   std::cout << "Something bad happened" << std::endl;
   return false;
 }
}

void GameView::loadMapFromAsset(MapView *mapView) {
  if (worldView) {
    worldView->from(mapView);
    delete mapView;
  } else {
    tempMapView = mapView;

    sigc::slot<bool> slot = sigc::bind<::Window>(sigc::mem_fun(*this, &GameView::onInitSDL), socket->get_id());
    Glib::signal_timeout().connect(slot, DRAW_TIME_STEP);
  }
}

bool GameView::onInitSDL(::Window windowId) {
 try {
   // Initialize SDL library
   sdl = new SDL2pp::SDL(SDL_INIT_VIDEO);

   SDL_Window *socketWindow = SDL_CreateWindowFrom((void *) windowId);
   if (!socketWindow)
     throw std::exception();

   mainWindow = new SDL2pp::Window(socketWindow);

   // Create accelerated video renderer with default driver
   renderer = new SDL2pp::Renderer(*mainWindow, -1, SDL_RENDERER_SOFTWARE);

   worldView = new WorldView(renderer);
   stintv = new SomethingThatIsNotTerrainView(renderer);

   worldView->from(tempMapView);
   delete tempMapView;

   sigc::slot<bool> slot = sigc::mem_fun(*this, &GameView::onLoopSDL);
   Glib::signal_timeout().connect(slot, DRAW_TIME_STEP);

   return false;
 } catch (std::exception& e) {
   std::cout << "Something bad happened" << std::endl;
   return true;
 }
}

void GameView::setKeyPressListener(OnKeyPressListener *listener) {
  this->listener = listener;
}

bool GameView::on_key_press_event(GdkEventKey* event) {
  if (listener)
    return listener->onKeyPressEvent(event);
  return Gtk::Window::on_key_press_event(event);
}

bool GameView::on_key_release_event(GdkEventKey* event) {
  if (listener)
    return listener->onKeyPressEvent(event);
  return Gtk::Window::on_key_release_event(event);
}
