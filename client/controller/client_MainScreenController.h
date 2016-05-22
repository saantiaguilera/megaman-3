#ifndef CLIENT_EVENTS_CLIENT_MAINSCREENCONTROLLER_H_
#define CLIENT_EVENTS_CLIENT_MAINSCREENCONTROLLER_H_

#include <gtkmm.h>
#include "../view/client_MainScreenView.h"
#include "../commons/client_Context.h"
#include "../commons/client_Controller.h"

class MainScreenController : public Controller, private OnEnterPressedInterface {
private:
  MainScreenView *view;

  /**
  * Has private inheritance. Why should any class know i can handle this
  * Since this is something internal of this controller, I think its ok
  */
  virtual void onEnterPressed(Gtk::Entry *editText);

  virtual bool onMessageReceived();

public:
  virtual Gtk::Window * getView();

  virtual void setVisibility(bool visible);

  virtual ~MainScreenController();

  /**
   * Create builder, parse xml, delegate inflate responsibility, set callbacks
   */
  MainScreenController(Context *context);
};

#endif /* CLIENT_EVENTS_CLIENT_MAINSCREENCONTROLLER_H_ */
