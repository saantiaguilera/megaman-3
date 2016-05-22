#ifndef CLIENT_CLIENT_GAMECONTROLLER_H_
#define CLIENT_CLIENT_GAMECONTROLLER_H_

#include <iostream>
#include <X11/Xlib.h>
#include <gtkmm.h>
#include <gtkmm/socket.h>
#include <SDL.h>

#include "concurrent/client_ConnectionThread.h"
#include "../concurrent/client_Looper.h"

#include "../commons/client_Handler.h"

class Context;

#include "../commons/client_Controller.h"
#include "../commons/client_Context.h"

#include "../../Constants.h"

#include "../client_Client.h"

/**
  * Im gonna copy as much as I can the Android MVC + everything I can
  * (eg Use of callbacks from user responses)
  *
  * Since this is mega fast sonic gotta go fast coding Im not gonna do
  * .cpp files and the MVC pattern im prolly gonna implement it in a
  * whole .h file for making include's problems dissappear
  */

  /*
  Working with SDL && GTKmm:
  1. Create the usual GTKmm stuff you will want to display, where you will place the SDL stuff just leave an empty container
  2. Add in that container a Gtk::Socket (Set wver you want, like size or styles)
  3. Connect a signal timeout (put whatever you want is timeout millis) to execute a bool method that will init sdl
  Eg.
  sigc::slot<bool> slot = sigc::bind<::Window>(sigc::mem_fun(*this, &aClass::initSDLMethod), theSocket->get_id());
  Glib::signal_timeout().connect(slot, 200);

  Note: When you init the SDL you will need a ::Window (From x11 lib). This value you can get it from the socket->get_id()

  4. Inside the initSDLMethod init the SDL with GTKmm. A simple example could be

  SDL_VideoInit(NULL)
  SDL_Window *window = SDL_CreateWindowFrom((void *) windowId); //windowId its the param we receive from the function (the ::Window)
  SDL_Surface *surface = SDL_GetWindowSurface(window);

  sigc::slot<bool> slot = sigc::mem_fun(*this, &aClass::loopSDLMethod);
  Glib::signal_timeout().connect(slot, 16);

  Note: See that SDL doesnt even realize we are using GTKmm with him, the "connection" is done via the socket window id !

  5. Do your stuff in the loopSDLMethod we are connecting there.

  Notes:
  - the Glib::signal_timout().connect() method has to return a boolean. This means:
  If you return true: It will continue connected and it will be called again after the timeout passes (its like keep looping)
  If you return false: It will dettach from the connections and you wont be called again.
  */

/* ---------------------- VIEW ---------------------- */

class GameView : public Gtk::Window {
private:
  SDL_Surface *surface;
  SDL_Surface *image;
  SDL_Window *window;

  bool onLoopSDL() {
    image = SDL_LoadBMP("res/drawable/tile_01.bmp");
    if (!image) {
      std::cout << "Couldn't load image: " << SDL_GetError() << std::endl;
      return false;
    }

    SDL_BlitSurface(image, NULL, surface, NULL);

    SDL_UpdateWindowSurface(window);

    return true;
  }

  bool onInitSDL(::Window windowId) {
    if (SDL_VideoInit(NULL) < 0) {
      std::cout << "Couldn't initialize SDL video: " << SDL_GetError()
                << std::endl;
      return true;
    }

    window = SDL_CreateWindowFrom((void *) windowId);
    if (!window) {
      std::cout << "Couldn't create SDL window: " << SDL_GetError() << std::endl;
      return true;
    }

    surface = SDL_GetWindowSurface(window);
    if (!surface) {
      std::cout << "Couldn't obtain SDL window surface: " << SDL_GetError() << std::endl;
      return true;
    }

    sigc::slot<bool> slot = sigc::mem_fun(*this, &GameView::onLoopSDL);
    Glib::signal_timeout().connect(slot, 16);

    return false;
  }

public:
  GameView() : Gtk::Window() {
    set_size_request(640, 480);

    Gtk::Socket *socket = manage(new Gtk::Socket());

    add(*socket);
    show_all();

    sigc::slot<bool> slot = sigc::bind<::Window>(sigc::mem_fun(*this, &GameView::onInitSDL), socket->get_id());
    Glib::signal_timeout().connect(slot, 50);
  }

  virtual ~GameView() {
    if (image) {
      SDL_FreeSurface(image);
      image = NULL;
    }

    if (surface) {
      SDL_FreeSurface(surface);
      surface = NULL;
    }

    if (window) {
      SDL_DestroyWindow(window);
      window = NULL;
    }

    SDL_Quit();
  }
};

/* ---------------------- CONTROLLER ---------------------- */

class GameController : public Controller {
private:
  GameView *view;

  virtual bool onMessageReceived() {
    return true;
  }

public:
  virtual Gtk::Window * getView() { return view; }

  virtual void setVisibility(bool visible) {
    if (!view)
      return;

    if (visible)
      view->show();
    else view->hide();
  }

  virtual ~GameController() { }

  /**
   * Create builder, parse xml, delegate inflate responsibility, set callbacks
   */
  GameController(Context *context) : Controller(context), view(nullptr) {
    view = new GameView();
  }
};

#endif
