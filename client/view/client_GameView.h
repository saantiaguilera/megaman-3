#ifndef CLIENT_GAMEVIEW_H_
#define CLIENT_GAMEVIEW_H_

#include <X11/Xlib.h>
#include <SDL2pp/SDL2pp.hh>

#include <gtkmm.h>

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
  SDL2pp::SDL *sdl;
  SDL2pp::Window *mainWindow;
  SDL2pp::Renderer *renderer;
  SDL2pp::Texture *sprites;

  /**
   * This method should be in charge of drawing everything
   * ofc it will delegate to other classes their stuff, but only here things will get drawn (which is called every 16ms)
   * as the Glib::conect signal marks.
   * All changes we receive from the server should manipulate the models (with locks !) from other threads, while this dude
   * will loop and just draw what it has to draw (and well, the model will have a different sprite and position, but this
   * method will never realize)
   *
   * Create classes for the SDL classes, that wrap their functionality.
   * Also create views for them (like MonsterView, which could be a wrapper of an SDL_Texture
   * class that also has functionality of a monster)
   *
   * Handle clicks and stuff not via SDL. Do them via GTKMM and just post them to a Looper instance (not the main one !!!!!)
   * and let the connection thread polls them and manage them
   *
   * I think thats all of it
   */
  bool onLoopSDL();
  bool onInitSDL(::Window windowId);

public:
  GameView();
  virtual ~GameView();
};

#endif
