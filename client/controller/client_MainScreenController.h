#ifndef CLIENT_EVENTS_CLIENT_MAINSCREENCONTROLLER_H_
#define CLIENT_EVENTS_CLIENT_MAINSCREENCONTROLLER_H_

#include <iostream>
#include <gtkmm.h>

/**
  * Im gonna copy as much as I can the Android MVC + everything I can
  * (eg Use of callbacks from user responses)
  *
  * Since this is mega fast sonic gotta go fast coding Im not gonna do
  * .cpp files and the MVC pattern im prolly gonna implement it in a
  * whole .h file for making include's problems dissappear
  */

/* ---------------------- INTERFACES ---------------------- */

/**
 * Simple interface, nothing weird to comment about it
 */
class OnEnterPressedInterface {
public:
  virtual void onEnterPressed(Gtk::Entry *editText) = 0;
};

/* ---------------------- VIEW ---------------------- */

#define PATH_EDIT_TEXT_VIEW "client_home_screen_edit_text"

class MainScreenView : public Gtk::Window {
private:
    Gtk::Entry *editText = nullptr;
    OnEnterPressedInterface *callback = NULL;

    /**
     * Simple method that justs dispatches to the interface if exists
     * Else its default behaviour its nothing
     */
    void onEnterPressed(Gtk::Entry *editText) {
      if (callback)
        callback->onEnterPressed(editText);
    }

public:
  MainScreenView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) :
          Gtk::Window(cobject) {
    refBuilder->get_widget(PATH_EDIT_TEXT_VIEW, editText);

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
};

/* ---------------------- CONTROLLER ---------------------- */

#define PATH_LAYOUT "res/layout/home_screen.glade"
#define PATH_ROOT_VIEW "client_home_screen_root_view"

class MainScreenController : private OnEnterPressedInterface {
private:
  MainScreenView *view;

  /**
  * Has private inheritance. Why should any class know i can handle this
  * Since this is something internal of this controller, I think its ok
  */
  virtual void onEnterPressed(Gtk::Entry *editText) {
    std::cout << "IP is " << editText->get_text() << std::endl;
  }

public:
  /**
   * I should create a generic Controller class that already has this method
   */
  Gtk::Window * getView() { return view; };

  virtual ~MainScreenController() { }

  /**
   * Create builder, parse xml, delegate inflate responsibility, set callbacks
   */
  MainScreenController() : view(nullptr) {
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
