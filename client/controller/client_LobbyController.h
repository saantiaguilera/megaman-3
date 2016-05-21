#ifndef CLIENT_CLIENT_LOBBYCONTROLLER_H_
#define CLIENT_CLIENT_LOBBYCONTROLLER_H_

#include <iostream>
#include <gtkmm.h>

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

/* ---------------------- VIEW ---------------------- */


class LobbyView : public Gtk::Window {
public:
  LobbyView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) :
          Gtk::Window(cobject) {
  }

  virtual ~LobbyView() {}
};

/* ---------------------- CONTROLLER ---------------------- */

#define PATH_LOBBY_LAYOUT "res/layout/client_lobby.glade"
#define PATH_LOBBY_ROOT_VIEW "client_lobby_root_view"

class LobbyController : public Controller {
private:
  LobbyView *view;

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

  virtual ~LobbyController() { }

  /**
   * Create builder, parse xml, delegate inflate responsibility, set callbacks
   */
  LobbyController(Context *context) : Controller(context), view(nullptr) {
    auto refBuilder = Gtk::Builder::create();

    try {
      refBuilder->add_from_file(PATH_LOBBY_LAYOUT);
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

    refBuilder->get_widget_derived(PATH_LOBBY_ROOT_VIEW, view);
  }
};

#endif
