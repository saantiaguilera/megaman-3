#ifndef CLIENT_CLIENT_GAMECONTROLLER_H_
#define CLIENT_CLIENT_GAMECONTROLLER_H_

#include <gtkmm.h>
#include "../commons/client_Context.h"
#include "../commons/client_Controller.h"
#include "../view/client_GameView.h"

class GameController : public Controller {
private:
  GameView *view;

  virtual bool onMessageReceived();

public:
  virtual Gtk::Window * getView();
  virtual void setVisibility(bool visible);

  virtual ~GameController();
  GameController(Context *context);
};

#endif
