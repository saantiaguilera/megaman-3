#include <iostream>
#include <gtkmm/socket.h>

#include "client_GameView.h"

GameView::GameView() : Gtk::Window() {
  std::cout << "creating new GameView" << std::endl;
  set_size_request(640, 480);

  Gtk::Socket *socket = manage(new Gtk::Socket());

  add(*socket);
  show_all();

  sigc::slot<bool> slot = sigc::bind<::Window>(sigc::mem_fun(*this, &GameView::onInitSDL), socket->get_id());
  Glib::signal_timeout().connect(slot, 50);
}

GameView::~GameView() {
  //TODO Free SDL stuff
}

bool GameView::onLoopSDL() {
 try {
   std::cout << "onLoopSDL" << std::endl;

   SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
   SDL_RenderClear(render);
   SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
   SDL_RenderDrawLine(render, 0, 0, 640, 480);
   SDL_RenderPresent(render);

   return true;
 } catch (std::exception& e) {
   std::cout << "Something bad happened" << std::endl;
   return false;
 }
}

bool GameView::onInitSDL(::Window windowId) {
 try {
   std::cout << "onInitSDL" << std::endl;

   if (SDL_VideoInit(NULL) < 0) {
     std::cerr << "Couldn't initialize SDL video: " << SDL_GetError()
               << std::endl;
     exit(1);
   }

   std::cout << "new SDL(SDLINITVIEO)" << std::endl;

   socketWindow = SDL_CreateWindowFrom((void *) windowId);
   if (!socketWindow)
     throw std::exception();

   render = SDL_CreateRenderer(socketWindow, -1, SDL_RENDERER_SOFTWARE);
   if (!render) {
     std::cerr << "Couldn't create renderer: " << SDL_GetError() << std::endl;
     exit(1);
   }

   sigc::slot<bool> slot = sigc::mem_fun(*this, &GameView::onLoopSDL);
   Glib::signal_timeout().connect(slot, 16);

   std::cout << "Initialized" << std::endl;

   return false;
 } catch (std::exception& e) {
   std::cout << "Something bad happened" << std::endl;
   return true;
 }
}
