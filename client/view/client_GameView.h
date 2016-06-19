#ifndef CLIENT_GAMEVIEW_H_
#define CLIENT_GAMEVIEW_H_

#include <SDL2pp/SDL2pp.hh>

#include <vector>
#include <gtkmm.h>
#include <gtkmm/socket.h>
#include <X11/Xlib.h>

// TODO This two wont be here (because I will put all the RenderedView's in a list, instead of having them stored in the class)
#include "../controller/client_SoundController.h"
#include "game_engine/client_WorldView.h"
#include "game_engine/client_AnimatedView.h"
#include "game_engine/client_AnimatedFactoryView.h"
#include "game_engine/client_DefaultBarView.h"
#include "game_engine/client_LifeBarView.h"

#include "../../common/common_MapView.h"

#define SOCKET_SIZE 700

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
  static OnMyOwnViewMovementListener *viewMovementListener;

  Gtk::Socket *socket = NULL;

  SDL2pp::SDL *sdl = NULL;
  SDL2pp::Window *mainWindow = NULL;
  SDL2pp::Renderer *renderer = NULL;

  WorldView *worldView = NULL;
  MapView *tempMapView = NULL;

  DefaultBarView *healthBarView = NULL;
  DefaultBarView *ammoBarView = NULL;
  LifeBarView *lifeBarView = NULL;

  static AnimatedView * myView;
  static unsigned int myId;

  static AnimatedFactoryView *factoryView;
  static std::vector<AnimatedView*> animatedViews;
  static SoundController soundController;

  static Point massCenter;
  static void refreshMassCenter();

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
  void getDesktopResolution(int& horizontal, int& vertical);

public:
  GameView();
  virtual ~GameView();

  void loadMapFromAsset(MapView *mapView);

  //THIS IS HELLA AWFUL M8
  //TODO Due to time its gonna be static. Do it nice.
  static void addViewFromJSON(std::string json);
  static void removeViewFromJSON(std::string json);
  static void moveViewFromJSON(std::string json);
  static bool isRunning();

  void onBarChange(BarView bar, int amount);

  Point getMassCenter();
  AnimatedView * getMyView();

  void setMyId(unsigned int id);

  void setKeyPressListener(OnKeyPressListener *listener);
  void setMyOwnViewMovementListener(OnMyOwnViewMovementListener *listener);
};

#endif
