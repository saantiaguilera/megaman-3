#ifndef CLIENT_GAMEVIEW_H_
#define CLIENT_GAMEVIEW_H_

#include <SDL2pp/SDL2pp.hh>

#include <vector>
#include <gtkmm.h>
#include <gtkmm/socket.h>
#include <X11/Xlib.h>

#include "../controller/client_SoundController.h"
#include "game_engine/client_WorldView.h"
#include "game_engine/client_AnimatedView.h"
#include "game_engine/client_AnimatedFactoryView.h"
#include "game_engine/client_DefaultBarView.h"
#include "game_engine/client_LifeBarView.h"

#include "../../common/common_Mutex.h"

#include "../../common/common_MapView.h"

/**
*TODO Since we didnt had time, we had to implement some stuff in an ugly form.
Ideally it would have been:
-The receiver thread receives a creation / destruction / movement of an object and it queues
its action in a list.
-The game controller has a inner thread/runnable/looper which just deques a element
and performs the action it has
*/

#define SCREEN_SIZE_WIDTH 950
#define SCREEN_SIZE_HEIGHT 550

enum BarView {
  BAR_LIFE,
  BAR_HP,
  BAR_AMMO
};

class OnKeyPressListener {
public:
  ~OnKeyPressListener() {}
  virtual bool onKeyPressEvent(GdkEventKey *event) = 0;
};

class OnMyOwnViewMovementListener {
public:
  ~OnMyOwnViewMovementListener() {}
  virtual void onViewMoved() = 0;
};

/* ---------------------- VIEW ---------------------- */

class GameView : public Gtk::Window {
private:
  OnKeyPressListener *keyPressListener = NULL;
  OnMyOwnViewMovementListener *viewMovementListener = NULL;

  Gtk::Socket *socket = NULL;

  SDL2pp::SDL *sdl = NULL;
  SDL2pp::Window *mainWindow = NULL;
  SDL2pp::Renderer *renderer = NULL;

  WorldView *worldView = NULL;
  MapView *tempMapView = NULL;

  DefaultBarView *healthBarView = NULL;
  DefaultBarView *ammoBarView = NULL;
  LifeBarView *lifeBarView = NULL;

  SoundController * soundController = NULL;

  Mutex mutex;

  AnimatedView * myView = NULL;
  unsigned int myId = -1;

  AnimatedFactoryView *factoryView = NULL;
  std::vector<AnimatedView*> animatedViews;

  Point massCenter;
  bool massCenterCouldHaveChanged;

  void refreshMassCenter();

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

  bool on_key_press_event(GdkEventKey* event) override;
  bool on_key_release_event(GdkEventKey* event) override;

  void resetAnimations();

public:
  GameView();
  virtual ~GameView();

  void loadMapFromAsset(MapView *mapView);

  void addViewFromJSON(std::string json);
  void removeViewFromJSON(std::string json);
  void moveViewFromJSON(std::string json);
  bool isRunning();

  void onBarChange(BarView bar, int amount);

  Point getMassCenter();
  AnimatedView * getMyView();

  void setMyId(unsigned int id);

  void setKeyPressListener(OnKeyPressListener *listener);
  void setMyOwnViewMovementListener(OnMyOwnViewMovementListener *listener);
};

#endif
