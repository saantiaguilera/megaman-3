#include <iostream>
#include <sstream>

#include "../../common/common_MapConstants.h"
#include "../../common/rapidjson/document.h"
#include "client_GameView.h"

#define BACKGROUND_COLOR "black"
#define PATH_IC_LAUNCHER "res/drawable/ic_launcher.png"

#define DRAW_TIME_STEP 50

#define HEALTH_BAR_X 12
#define HEALTH_BAR_Y 12
#define AMMO_BAR_X 79
#define AMMO_BAR_Y 12
#define LIFE_BAR_X 146
#define LIFE_BAR_Y 5

AnimatedFactoryView * GameView::factoryView = NULL;
AnimatedView * GameView::myView = NULL;
OnMyOwnViewMovementListener * GameView::viewMovementListener = NULL;
unsigned int GameView::myId = -1;
bool GameView::massCenterCouldHaveChanged = false;
std::vector<AnimatedView*> GameView::animatedViews;
SoundController GameView::soundController;
Point GameView::massCenter;

GameView::GameView() : Gtk::Window(){
  myView = NULL;
  viewMovementListener = NULL;
  myId = -1;

  int screenWidth, screenHeight;
  getDesktopResolution(screenWidth, screenHeight);
  set_size_request(screenWidth, screenHeight);
  fullscreen();

  set_icon_from_file(PATH_IC_LAUNCHER);
  override_background_color(Gdk::RGBA(BACKGROUND_COLOR), Gtk::STATE_FLAG_NORMAL);


  massCenter.setX(0);
  massCenter.setY(0);

  socket = manage(new Gtk::Socket());
  socket->set_size_request(SOCKET_SIZE, SOCKET_SIZE);

  Gtk::Layout *layout = manage(new Gtk::Layout());
  layout->set_size_request(screenWidth, screenHeight);
  layout->put(*socket, (screenWidth - SOCKET_SIZE) / 2, (screenHeight - SOCKET_SIZE) / 2);

  add(*layout);
  show_all();
}

GameView::~GameView() {
  if (worldView) {
    delete worldView;
    worldView = NULL;
  }

  resetAnimations();

  if (ammoBarView) {
    delete ammoBarView;
    ammoBarView = NULL;
  }

  if (healthBarView) {
    delete healthBarView;
    healthBarView = NULL;
  }

  if (lifeBarView) {
    delete lifeBarView;
    lifeBarView = NULL;
  }

  if (renderer) {
    delete renderer;
    renderer = NULL;
  }

  if (mainWindow) {
    delete mainWindow;
    mainWindow = NULL;
  }

  if (sdl) {
    delete sdl;
    sdl = NULL;
  }

  viewMovementListener = NULL;
  myView = NULL;
  myId = -1;
}

Point GameView::getMassCenter() {
  return massCenter;
}

AnimatedView * GameView::getMyView() {
  return myView;
}

void GameView::setMyId(unsigned int id) {
  myId = id;

  if (!myView)
    for (AnimatedView * someView : animatedViews)
      if (someView->getId() == myId)
        myView = someView;

  massCenterCouldHaveChanged = true;
}

void GameView::resetAnimations() {
  if (factoryView) {
    delete factoryView;
    factoryView = NULL;
  }

  for (std::vector<AnimatedView*>::iterator it = animatedViews.begin() ;
    it != animatedViews.end() ; ++it) {
      delete (*it);
  }

  animatedViews.clear();

  massCenter.setX(0);
  massCenter.setY(0);
}

void GameView::addViewFromJSON(std::string json) {
  rapidjson::Document document;
  document.Parse(json.c_str());

  unsigned int viewId = document["id"].GetUint();
  int viewType = document["type"].GetInt();
  unsigned int positionX = document["position"]["x"].GetUint();
  unsigned int positionY = document["position"]["y"].GetUint();

  if (factoryView) {
    AnimatedView * view = factoryView->make(viewType, viewId);

    if (view) {
      Point point;
      point.setX(positionX);
      point.setY(positionY);
      view->set(point);

      //TODO Race conditions ?
      animatedViews.push_back(view);

      if (view->doesDeviateMassCenter())
        massCenterCouldHaveChanged = true;

      if (myId == viewId)
        myView = view;
		//We could create a doulbe dispatch for the soundcontroller. (like soundController->playFor(view);
    }
  }
}

void GameView::removeViewFromJSON(std::string json) {
  rapidjson::Document document;
  document.Parse(json.c_str());

  unsigned int id = document["id"].GetUint();
  int position = -1;

  for (unsigned int i = 0 ; i < animatedViews.size() ; ++i) {
    if (animatedViews.at(i)->getId() == id) {
      position = i;
      break;
    }
  }

  if (position != -1) {
    AnimatedView *view = animatedViews.at(position);
    animatedViews.erase(animatedViews.begin() + position);

    if (view->doesDeviateMassCenter())
      massCenterCouldHaveChanged = true;

    delete view;
  }
}

void GameView::moveViewFromJSON(std::string json) {
  rapidjson::Document document;
  document.Parse(json.c_str());

  unsigned int id = document["id"].GetUint();
  unsigned int positionX = document["position"]["x"].GetUint();
  unsigned int positionY = document["position"]["y"].GetUint();
  int index = -1;

  for (unsigned int i = 0 ; i < animatedViews.size() ; ++i) {
    if (animatedViews.at(i)->getId() == id) {
      index = i;
      break;
    }
  }

  if (index != -1) {
    AnimatedView * view = animatedViews.at(index);

    Point point;
    point.setX(positionX);
    point.setY(positionY);
    view->add(point);

    if (view->doesDeviateMassCenter())
      massCenterCouldHaveChanged = true;

    if ((view->getId() == myView->getId()) && viewMovementListener)
      viewMovementListener->onViewMoved();
  }
}

void GameView::setMyOwnViewMovementListener(OnMyOwnViewMovementListener *listener) {
  viewMovementListener = listener;
}

void GameView::refreshMassCenter() {
  int x = 0;
  int y = 0;
  int count = 0;

  for (AnimatedView* view : animatedViews) {
      if (view->doesDeviateMassCenter()) {
        x += view->getX();
        y += view->getY();

        count++;
      }
    }

  if (count > 0) {
    massCenter.setX(x / count);
    massCenter.setY(y / count);
  } else {
    massCenter.setX(0);
    massCenter.setY(0);
  }

  massCenterCouldHaveChanged = false;
}

bool GameView::onLoopSDL() {
  try {
    renderer->Clear();

    if (massCenterCouldHaveChanged)
      refreshMassCenter();

    //Uint32 t1 = SDL_GetTicks();

    worldView->draw(massCenter);

    //Uint32 t2 = SDL_GetTicks();
    //std::cout << "Time for drawing world is " << t2 - t1 << std::endl;
    //std::cout << "List size of views is " << animatedViews.size() << std::endl;

    for (AnimatedView* view : animatedViews)
      view->draw(massCenter);

    //Uint32 t3 = SDL_GetTicks();
    //std::cout << "Time for drawing megaman is " << t3 - t2 << std::endl;

    healthBarView->draw(massCenter);
    ammoBarView->draw(massCenter);
    lifeBarView->draw(massCenter);

    //Uint32 t4 = SDL_GetTicks();
    //std::cout << "Time for drawing bars is " << t4 - t3 << std::endl;

    renderer->Present();

    return true;
  } catch (std::exception& e) {
    std::cout << "Something bad happened in onLoopSDL" << std::endl;
    return false;
  }
}

void GameView::loadMapFromAsset(MapView *mapView) {
  if (worldView) {
    resetAnimations();
    worldView->from(mapView);
    delete mapView;
    factoryView = new AnimatedFactoryView(renderer);
  } else {
    tempMapView = mapView;

    onInitSDL(socket->get_id());

//    sigc::slot<bool> slot = sigc::bind<::Window>(sigc::mem_fun(*this, &GameView::onInitSDL), socket->get_id());
//    Glib::signal_timeout().connect(slot, DRAW_TIME_STEP);
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

   healthBarView = new DefaultBarView(renderer);
   healthBarView->setX(HEALTH_BAR_X);
   healthBarView->setY(HEALTH_BAR_Y);

   ammoBarView = new DefaultBarView(renderer);
   ammoBarView->setX(AMMO_BAR_X);
   ammoBarView->setY(AMMO_BAR_Y);

   lifeBarView = new LifeBarView(renderer);
   lifeBarView->setX(LIFE_BAR_X);
   lifeBarView->setY(LIFE_BAR_Y);

   worldView->from(tempMapView);

   delete tempMapView;

   factoryView = new AnimatedFactoryView(renderer);

   sigc::slot<bool> slot = sigc::mem_fun(*this, &GameView::onLoopSDL);
   Glib::signal_timeout().connect(slot, DRAW_TIME_STEP);

   return false;
 } catch (std::exception& e) {
   std::cout << "Something bad happened in onInitSDL" << std::endl;
   return true;
 }
}

void GameView::getDesktopResolution(int& horizontal, int& vertical) {
  Display* disp = XOpenDisplay(NULL);
  Screen* scrn = DefaultScreenOfDisplay(disp);
  vertical = scrn->height;
  horizontal = scrn->width;
}

bool GameView::isRunning() {
  return factoryView;
}

void GameView::onBarChange(BarView bar, int amount) {
  switch (bar) {
    case BAR_AMMO:
      ammoBarView->setAmountPercentage(amount);
      break;

    case BAR_HP:
      healthBarView->setAmountPercentage(amount);
      break;

    case BAR_LIFE:
      lifeBarView->setLifes(amount);
      break;
  }
}

void GameView::setKeyPressListener(OnKeyPressListener *listener) {
  keyPressListener = listener;
}

bool GameView::on_key_press_event(GdkEventKey* event) {
  if (keyPressListener)
    return keyPressListener->onKeyPressEvent(event);
  return Gtk::Window::on_key_press_event(event);
}

bool GameView::on_key_release_event(GdkEventKey* event) {
  if (keyPressListener)
    return keyPressListener->onKeyPressEvent(event);
  return Gtk::Window::on_key_release_event(event);
}
