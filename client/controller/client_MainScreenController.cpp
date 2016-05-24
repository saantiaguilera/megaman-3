#include <iostream>

#include "../concurrent/client_Looper.h"

#include "../../Constants.h"

#include "concurrent/event/client_CreateConnectionEvent.h"

#include "client_MainScreenController.h"

#define PATH_HOME_SCREEN_LAYOUT "res/layout/home_screen.glade"
#define PATH_HOME_SCREEN_ROOT_VIEW "client_home_screen_root_view"

MainScreenController::MainScreenController(Context *context) : Controller(context), view(nullptr) {
  auto refBuilder = Gtk::Builder::create();

  try {
    refBuilder->add_from_file(PATH_HOME_SCREEN_LAYOUT);
  } catch(const Glib::FileError& ex) {
    std::cout << "FileError: " << ex.what() << std::endl;
    return;
  } catch(const Glib::MarkupError& ex) {
    std::cout << "MarkupError: " << ex.what() << std::endl;
    return;
  } catch(const Gtk::BuilderError& ex) {
    std::cout << "BuilderError: " << ex.what() << std::endl;
    return;
  }

  refBuilder->get_widget_derived(PATH_HOME_SCREEN_ROOT_VIEW, view);

  view->setEnterPressedListener(this);
}

MainScreenController::~MainScreenController() {
  delete view;
}

void MainScreenController::onEnterPressed(Gtk::Entry *editText) {
  view->setResult(RESULT_INDETERMINATE);

  Looper::getMainLooper().put(new CreateConnectionEvent(editText->get_text()));
  getContext()->onMessageReceived();
}

bool MainScreenController::onMessageReceived() {
  Event *event = Looper::getMainLooper().get();

  if (event) {
    switch (event->getId()) {
      //Do stuff
      case EVENT_CONNECTION_ACCEPTED:
        view->setResult(RESULT_OK);
        break;

      case EVENT_CONNECTION_REFUSED:
        view->setResult(RESULT_ERROR);
        break;

      case EVENT_CONNECTION_SHUTDOWN:
        std::cout << "Disconnected" << std::endl;
        break;

      default:
        return false;
    }

    return true;
  } else return false;
}

Gtk::Window * MainScreenController::getView() {
  return view;
}

void MainScreenController::setVisibility(bool visible) {
  if (!view)
    return;

  if (visible)
    view->show();
  else view->hide();
}
