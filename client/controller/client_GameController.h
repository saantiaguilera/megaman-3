#ifndef CLIENT_CLIENT_GAMECONTROLLER_H_
#define CLIENT_CLIENT_GAMECONTROLLER_H_

#include "../commons/client_Context.h"
#include "../commons/client_Controller.h"
#include "client_KeyMap.h"
#include "../view/client_GameView.h"
#include "../concurrent/client_Looper.h"

class GameController : public Controller, private OnKeyPressListener {
private:
  GameView *view;

  KeyMap keyMap;

  virtual bool onMessageReceived();
  bool onKeyPressEvent(GdkEventKey *event);

public:
  virtual Gtk::Window * getView();
  virtual void setVisibility(bool visible);

  virtual ~GameController();
  GameController(Context *context);
};

#endif
