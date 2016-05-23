#include <iostream>
#include <gtkmm/socket.h>

#include "client_GameView.h"

GameView::GameView() : Gtk::Window() {
 set_size_request(1920, 1080);

 Gtk::Socket *socket = manage(new Gtk::Socket());

 add(*socket);
 show_all();

 sigc::slot<bool> slot = sigc::bind<::Window>(sigc::mem_fun(*this, &GameView::onInitSDL), socket->get_id());
 Glib::signal_timeout().connect(slot, 50);
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
   stintv->draw();

   renderer->Present();

   return true;
 } catch (std::exception& e) {
   std::cout << "Something bad happened" << std::endl;
   return false;
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

   sigc::slot<bool> slot = sigc::mem_fun(*this, &GameView::onLoopSDL);
   Glib::signal_timeout().connect(slot, 16);

   return false;
 } catch (std::exception& e) {
   std::cout << "Something bad happened" << std::endl;
   return true;
 }
}
