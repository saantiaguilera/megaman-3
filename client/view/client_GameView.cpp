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

}

bool GameView::onLoopSDL() {
 try {
   renderer.Clear();

   renderer.Copy(sprites);

   renderer.Present();

   return true;
 } catch (std::exception& e) {
   return false;
 }
}

bool GameView::onInitSDL(::Window windowId) {
 try {
   // Initialize SDL library
   sdl(SDL_INIT_VIDEO);

   SDL_Window *socketWindow = SDL_CreateWindowFrom((void *) windowId);
   if (!socketWindow)
     throw std::exception();

   mainWindow(socketWindow);

   // Create accelerated video renderer with default driver
   renderer(window, -1, SDL_RENDERER_ACCELERATED);

   // Load sprites image as a new texture
   sprites(renderer, "res/drawable/some_tiles.png");

   sigc::slot<bool> slot = sigc::mem_fun(*this, &GameView::onLoopSDL);
   Glib::signal_timeout().connect(slot, 16);

   return false;
 } catch (std::exception& e) {
   return true;
 }
}
