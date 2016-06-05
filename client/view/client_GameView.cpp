#include <iostream>

#include "../../common/rapidjson/document.h"
#include "client_GameView.h"

#define DRAW_TIME_STEP 16

AnimatedFactoryView * GameView::factoryView = NULL;
std::vector<AnimatedView*> GameView::animatedViews;

GameView::GameView() : Gtk::Window() {
 set_size_request(800, 600); //TODO

 socket = manage(new Gtk::Socket());

 add(*socket);
 show_all();
}

GameView::~GameView() {
  if (worldView)
    delete worldView;

  if (factoryView) {
    delete factoryView;
    factoryView = NULL;
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
  std::cout << "addViewFromJSON" << std::endl;
  rapidjson::Document document;
  document.Parse(json.c_str());

  unsigned int viewId = document["id"].GetUint();
  int viewType = document["type"].GetInt();
  unsigned int positionX = (unsigned int) document["position"]["x"].GetUint();
  unsigned int positionY = (unsigned int) document["position"]["y"].GetUint();

  std::cout << "parsed stuff" << std::endl;

  if (factoryView) {
    std::cout << "factoryView exists" << std::endl;
    AnimatedView * view = factoryView->make(viewType, viewId);

    if (view) {
      view->setX(positionX);
      view->setY(positionY);

      std::cout << "created view" << std::endl;

      //TODO Race conditions ?
      animatedViews.push_back(view);

      std::cout << "animatedViews has one more element" << std::endl;
    }
  }
}

void GameView::removeViewFromJSON(std::string json) {
  std::cout << "removeViewFromJSON" << std::endl;
  rapidjson::Document document;
  document.Parse(json.c_str());

  unsigned int id = document["id"].GetUint();
  int position = -1;

  std::cout << "parsed stuff" << std::endl;

  for (unsigned int i = 0 ; i < animatedViews.size() ; ++i) {
    if (animatedViews.at(i)->getId() == id) {
      position = i;
      break;
    }
  }

  std::cout << "position to remove is " << position << std::endl;

  if (position != -1) {
    delete animatedViews.at(position);
    animatedViews.erase(animatedViews.begin() + position);
  }
}

void GameView::moveViewFromJSON(std::string json) {
  std::cout << "moveViewFROMJSON" << std::endl;
  rapidjson::Document document;
  document.Parse(json.c_str());

  unsigned int id = document["id"].GetUint();
  unsigned int positionX = document["position"]["x"].GetUint();
  unsigned int positionY = document["position"]["y"].GetUint();
  int index = -1;

  std::cout << "parsed stuff" << std::endl;

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
  }
}

bool GameView::onLoopSDL() {
  try {
    renderer->Clear();

    Point massCenter;
    massCenter.setX(0);
    massCenter.setY(0);

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
