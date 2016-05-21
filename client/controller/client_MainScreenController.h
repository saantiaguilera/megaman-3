#ifndef CLIENT_EVENTS_CLIENT_MAINSCREENCONTROLLER_H_
#define CLIENT_EVENTS_CLIENT_MAINSCREENCONTROLLER_H_

#include <iostream>
#include <gtkmm.h>

#include "concurrent/client_ConnectionThread.h"
#include "../concurrent/client_Looper.h"

#include "client_Handler.h"

class Context;

#include "client_Controller.h"
#include "client_Context.h"

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

/* ---------------------- OTHERS ---------------------- */

/**
 * Simple interface, nothing weird to comment about it
 */
class OnEnterPressedInterface {
  public:
    virtual void onEnterPressed(Gtk::Entry *editText) = 0;
};

/* ---------------------- VIEW ---------------------- */

#define PATH_EDIT_TEXT_VIEW "client_home_screen_edit_text"
#define PATH_PROGRESS_BAR_VIEW "client_home_screen_progress_bar"
#define PATH_RESULT_TEXT_VIEW "client_home_screen_result_text_view"

class MainScreenView : public Gtk::Window {
private:
    Gtk::Entry *editText = nullptr;
    Gtk::Spinner *progressBar = nullptr;
    Gtk::Label *resultText = nullptr;

    OnEnterPressedInterface *callback = NULL;

    /**
     * Simple method that justs dispatches to the interface if exists
     * Else its default behaviour its nothing
     */
    void onEnterPressed(Gtk::Entry *editText) {
      if (callback)
        callback->onEnterPressed(editText);
    }

    void setProgressBarIndeterminate(bool active) {
      if (active)
        progressBar->start();
      else progressBar->stop();
    }

public:
  MainScreenView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) :
          Gtk::Window(cobject) {
    refBuilder->get_widget(PATH_EDIT_TEXT_VIEW, editText);
    refBuilder->get_widget(PATH_PROGRESS_BAR_VIEW, progressBar);
    refBuilder->get_widget(PATH_RESULT_TEXT_VIEW, resultText);

    if(editText)
      editText->signal_activate().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this, &MainScreenView::onEnterPressed), editText));
  }

  virtual ~MainScreenView() {}

  /**
   * Setter if someone wants to do something about the Enter pressing
   */
  void setOnEnterPressedListener(OnEnterPressedInterface *listener) {
    callback = listener;
  }

  void setResult(ConnectionResult result) {
    switch (result) {
      case RESULT_OK:
        setProgressBarIndeterminate(false);
        resultText->set_text("CONNECTED");
        resultText->override_color(Gdk::RGBA("green"), Gtk::STATE_FLAG_NORMAL);
        break;

      case RESULT_INDETERMINATE:
        setProgressBarIndeterminate(true);
        resultText->set_text("");
        break;

      case RESULT_ERROR:
        setProgressBarIndeterminate(false);
        resultText->set_text("AN ERROR HAS OCCURED. PLS TRY AGAIN");
        resultText->override_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
    }
  }
};

/* ---------------------- CONTROLLER ---------------------- */

#define PATH_LAYOUT "res/layout/home_screen.glade"
#define PATH_ROOT_VIEW "client_home_screen_root_view"

class MainScreenController : public Controller, private OnEnterPressedInterface {
private:
  MainScreenView *view;

  /**
  * Has private inheritance. Why should any class know i can handle this
  * Since this is something internal of this controller, I think its ok
  */
  virtual void onEnterPressed(Gtk::Entry *editText) {
    view->setResult(RESULT_INDETERMINATE);

    //TODO Looper::getMainLooper().put(new CreateConnectionEvent(editText->get_text()));
    getContext()->onMessageReceived();
  }

  virtual bool onMessageReceived() {
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
      } else return false;

      return true;
    }
  }

public:
  virtual Gtk::Window * getView() { return view; };

  virtual void setVisibility(bool visible) {
    if (!view)
      return;

    if (visible)
      view->show();
    else view->hide();
  }

  virtual ~MainScreenController() { }

  /**
   * Create builder, parse xml, delegate inflate responsibility, set callbacks
   */
  MainScreenController(Context context) : Controller(context), view(nullptr) {
    auto refBuilder = Gtk::Builder::create();

    try {
      refBuilder->add_from_file(PATH_LAYOUT);
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

    refBuilder->get_widget_derived(PATH_ROOT_VIEW, view);

    view->setOnEnterPressedListener(this);
  }
};

#endif /* CLIENT_EVENTS_CLIENT_MAINSCREENCONTROLLER_H_ */
