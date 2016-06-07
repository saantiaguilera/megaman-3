#include <iostream>
#include <sstream>

#include "../../common/common_MapConstants.h"
#include "../../common/rapidjson/document.h"
#include "client_GameView.h"

#define PATH_GAME_VIEW_CONTAINER "game_view_layout"
#define PATH_GAME_VIEW_SOCKET_CONTAINER "game_view_socket_container"
#define PATH_GAME_VIEW_HP_BAR "game_view_hp_label"
#define PATH_GAME_VIEW_LIFE_BAR "game_view_life_label"
#define PATH_GAME_VIEW_AMMO_BAR "game_view_ammo_label"
#define PATH_GAME_VIEW_SPECIAL_AMMO_BAR "game_view_special_ammo_label"

#define DRAW_TIME_STEP 33 //30 fps

AnimatedFactoryView * GameView::factoryView = NULL;
std::vector<AnimatedView*> GameView::animatedViews;
SDL2pp::Mixer * GameView::mixer = NULL;
SDL2pp::Chunk * GameView::shootSound = NULL;
Point GameView::massCenter;

GameView::GameView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) :
        Gtk::Window(cobject){

  refBuilder->get_widget(PATH_GAME_VIEW_CONTAINER, containerView);
  refBuilder->get_widget(PATH_GAME_VIEW_SOCKET_CONTAINER, socketContainerView);
  refBuilder->get_widget(PATH_GAME_VIEW_HP_BAR, hpBarView);
  refBuilder->get_widget(PATH_GAME_VIEW_LIFE_BAR, lifeBarView);
  refBuilder->get_widget(PATH_GAME_VIEW_AMMO_BAR, ammoBarView);
  refBuilder->get_widget(PATH_GAME_VIEW_SPECIAL_AMMO_BAR, specialAmmoBarView);

  set_size_request(800, 600); //TODO
  socketContainerView->set_size_request(800, 600);

  socket = manage(new Gtk::Socket());

  if (!shootSound)
    shootSound = new SDL2pp::Chunk("res/sound/shoot.mp3");
  if (!mixer)
    mixer = new SDL2pp::Mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

  socketContainerView->add(*socket);
  show_all();
}

GameView::~GameView() {
  if (worldView)
    delete worldView;

  if (factoryView) {
    delete factoryView;
    factoryView = NULL;
  }

  if (mixer) {
    delete mixer;
    mixer = NULL;
  }

  if (shootSound) {
    delete shootSound;
    shootSound = NULL;
  }

  for (std::vector<AnimatedView*>::iterator it = animatedViews.begin() ;
    it != animatedViews.end() ; ++it) {
      delete (*it);
  }

  animatedViews.clear();
  if (renderer)
    delete renderer;

  if (mainWindow)
    delete mainWindow;

  if (sdl)
    delete sdl;
}

void GameView::addViewFromJSON(std::string json) {
  rapidjson::Document document;
  document.Parse(json.c_str());

  unsigned int viewId = document["id"].GetUint();
  int viewType = document["type"].GetInt();
  unsigned int positionX = (unsigned int) document["position"]["x"].GetFloat();
  unsigned int positionY = (unsigned int) document["position"]["y"].GetFloat();

  if (factoryView) {
    AnimatedView * view = factoryView->make(viewType, viewId);

    if (view) {
      view->setX(positionX);
      view->setY(positionY);

      //TODO Race conditions ?
      animatedViews.push_back(view);

      if (view->doesDeviateMassCenter())
        refreshMassCenter();

      //Its a bullet, play sound
      if (viewType >= ObstacleViewTypeBomb && viewType <= ObstacleViewTypePlasma)
        mixer->PlayChannel(-1, *shootSound);
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
      refreshMassCenter();

    delete view;
  }
}

void GameView::moveViewFromJSON(std::string json) {
  rapidjson::Document document;
  document.Parse(json.c_str());

  unsigned int id = document["id"].GetUint();
  unsigned int positionX = (unsigned int) document["position"]["x"].GetFloat();
  unsigned int positionY = (unsigned int) document["position"]["y"].GetFloat();
  int index = -1;

  for (unsigned int i = 0 ; i < animatedViews.size() ; ++i) {
    if (animatedViews.at(i)->getId() == id) {
      index = i;
      break;
    }
  }

  if (index != -1) {
    AnimatedView * view = animatedViews.at(index);

    view->setX(positionX);
    view->setY(positionY);

    if (view->doesDeviateMassCenter())
      refreshMassCenter();
  }
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

  massCenter.setX(x / count);
  massCenter.setY(y / count);
}

bool GameView::onLoopSDL() {
  try {
    renderer->Clear();

    worldView->draw(massCenter);

    for (AnimatedView* view : animatedViews)
      view->draw(massCenter);

    renderer->Present();

    return true;
  } catch (std::exception& e) {
    std::cout << "Something bad happened" << std::endl;
    return false;
  }
}

void GameView::loadMapFromAsset(MapView *mapView) {
  if (worldView) {
    worldView->from(mapView);
    delete mapView;
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

   factoryView = new AnimatedFactoryView(renderer);

   worldView = new WorldView(renderer);

   worldView->from(tempMapView);
   delete tempMapView;

   sigc::slot<bool> slot = sigc::mem_fun(*this, &GameView::onLoopSDL);
   Glib::signal_timeout().connect(slot, DRAW_TIME_STEP);

   return false;
 } catch (std::exception& e) {
   std::cout << "Something bad happened" << std::endl;
   return true;
 }
}

bool GameView::isRunning() {
  return factoryView;
}

void GameView::onBarChange(BarView bar, int amount) {
  std::stringstream text;
  switch (bar) {
    case BAR_AMMO:
      text << "Ammunition: " << amount;
      ammoBarView->set_text(text.str());
      break;

    case BAR_SPECIAL_AMMO:
      text << "Special Ammunition: " << amount;
      specialAmmoBarView->set_text(text.str());
      break;

    case BAR_HP:
      text << "HP: " << amount;
      hpBarView->set_text(text.str());
      break;

    case BAR_LIFE:
      text << "Lifes: " << amount;
      lifeBarView->set_text(text.str());
      break;
  }
}

void GameView::setKeyPressListener(OnKeyPressListener *listener) {
  this->listener = listener;
}

bool GameView::on_key_press_event(GdkEventKey* event) {
  if (listener)
    return listener->onKeyPressEvent(event);
  return Gtk::Window::on_key_press_event(event);
}

bool GameView::on_key_release_event(GdkEventKey* event) {
  if (listener)
    return listener->onKeyPressEvent(event);
  return Gtk::Window::on_key_release_event(event);
}
