#include <iostream>
#include <sstream>

#include "../../common/common_MapConstants.h"
#include "../../common/rapidjson/document.h"
#include "../../common/common_Lock.h"
#include "client_GameView.h"

#define BACKGROUND_COLOR "black"
#define PATH_IC_LAUNCHER "res/drawable/ic_launcher.png"

#define HEALTH_BAR_X 12
#define HEALTH_BAR_Y 12
#define AMMO_BAR_X 79
#define AMMO_BAR_Y 12
#define LIFE_BAR_X 146
#define LIFE_BAR_Y 5

GameView::GameView() : Gtk::Window() {
  set_size_request(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT);

  set_icon_from_file(PATH_IC_LAUNCHER);
  override_background_color(Gdk::RGBA(BACKGROUND_COLOR), Gtk::STATE_FLAG_NORMAL);

  massCenter.setX(0);
  massCenter.setY(0);

  socket = manage(new Gtk::Socket());

  add(*socket);
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

  if (soundController) {
    delete soundController;
    soundController = NULL;
  }

  if (sdl) {
    delete sdl;
    sdl = NULL;
  }
}

void GameView::setFramesPerSecond(int fps) {
  int millis = (1000 / fps);

  if (millis > DEFAULT_DRAW_TIME_STEP)
    framesPerSecondInMillis = millis;
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

  {
    Lock lock(mutex);
    for (std::vector<AnimatedView*>::iterator it = animatedViews.begin() ;
      it != animatedViews.end() ; ++it) {
        delete (*it);
    }

    animatedViews.clear();
  }

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

      {
        Lock lock(mutex);
        animatedViews.push_back(view);
      }

      if (view->doesDeviateMassCenter())
        massCenterCouldHaveChanged = true;

      if (myId == viewId)
        myView = view;
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
    AnimatedView *view;

    {
      Lock lock(mutex);
      view = animatedViews.at(position);
      animatedViews.erase(animatedViews.begin() + position);
    }

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
  AnimatedView *view = NULL;

  for (AnimatedView * aView : animatedViews) {
    if (aView->getId() == id) {
      view = aView;
      break;
    }
  }

  if (view) {
    Point point;
    point.setX(positionX);
    point.setY(positionY);
    view->add(point);

    if (view->doesDeviateMassCenter())
      massCenterCouldHaveChanged = true;

    if (myView && (view->getId() == myView->getId()) && viewMovementListener)
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
    if (mainWindow->GetSize().GetX() != get_width() || mainWindow->GetSize().GetY() != get_height())
      mainWindow->SetSize(SDL2pp::Point(get_width(), get_height()));

    if (massCenterCouldHaveChanged)
      refreshMassCenter();

    renderer->Clear();

    //Uint32 t1 = SDL_GetTicks();

    worldView->draw(massCenter);

    //Uint32 t2 = SDL_GetTicks();
    //std::cout << "Time for drawing world is " << t2 - t1 << std::endl;
    //std::cout << "List size of views is " << animatedViews.size() << std::endl;

    {
      Lock lock(mutex);
      for (AnimatedView* view : animatedViews)
        view->draw(massCenter);
    }

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

    //If we dont have a factory we will wait for creating them, so create the factory when we are sure we have the map ;)
    factoryView = new AnimatedFactoryView(renderer);
  } else {
    tempMapView = mapView;

    onInitSDL(socket->get_id());
  }
}

bool GameView::onInitSDL(::Window windowId) {
 try {
   // Initialize SDL library
   sdl = new SDL2pp::SDL(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

   SDL_Window *socketWindow = SDL_CreateWindowFrom((void *) windowId);
   if (!socketWindow)
     throw std::exception();

   mainWindow = new SDL2pp::Window(socketWindow);

   // Create accelerated video renderer with default driver
   renderer = new SDL2pp::Renderer(*mainWindow, -1, SDL_RENDERER_SOFTWARE);
   SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
   renderer->SetLogicalSize(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT);

   worldView = new WorldView(renderer);

   healthBarView = new DefaultBarView(LIFE, renderer);
   healthBarView->setX(HEALTH_BAR_X);
   healthBarView->setY(HEALTH_BAR_Y);

   ammoBarView = new DefaultBarView(AMMO, renderer);
   ammoBarView->setX(AMMO_BAR_X);
   ammoBarView->setY(AMMO_BAR_Y);

   lifeBarView = new LifeBarView(renderer);
   lifeBarView->setX(LIFE_BAR_X);
   lifeBarView->setY(LIFE_BAR_Y);

   worldView->from(tempMapView);

   delete tempMapView;

   factoryView = new AnimatedFactoryView(renderer);
   soundController = new SoundController();

   sigc::slot<bool> slot = sigc::mem_fun(*this, &GameView::onLoopSDL);
   Glib::signal_timeout().connect(slot, framesPerSecondInMillis);

   return false;
 } catch (std::exception& e) {
   std::cout << "Something bad happened in onInitSDL" << std::endl;
   return true;
 }
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
