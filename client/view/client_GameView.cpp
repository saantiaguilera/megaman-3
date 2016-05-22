#include <iostream>
#include <gtkmm/socket.h>

#include "client_GameView.h"

GameView::GameView() : Gtk::Window() {
 set_size_request(640, 480);

 Gtk::Socket *socket = manage(new Gtk::Socket());

 add(*socket);
 show_all();

 sigc::slot<bool> slot = sigc::bind<::Window>(sigc::mem_fun(*this, &GameView::onInitSDL), socket->get_id());
 Glib::signal_timeout().connect(slot, 50);
}

GameView::~GameView() {
  delete sprites;
  delete renderer;
  delete mainWindow;
  delete sdl;
}

bool GameView::onLoopSDL() {
 try {
   renderer->Clear();

   renderer->Copy(*sprites);

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

   // Load sprites image as a new texture
   sprites = new SDL2pp::Texture(*renderer, "res/drawable/some_tiles.png");

   sigc::slot<bool> slot = sigc::mem_fun(*this, &GameView::onLoopSDL);
   Glib::signal_timeout().connect(slot, 16);

   return false;
 } catch (std::exception& e) {
   std::cout << "Something bad happened" << std::endl;
   return true;
 }
}
