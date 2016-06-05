#ifndef CLIENT_CLIENT_GAMECONTROLLER_H_
#define CLIENT_CLIENT_GAMECONTROLLER_H_

#include "../commons/client_Context.h"
#include "../commons/client_Controller.h"
#include "client_KeyMap.h"
#include "../view/client_GameView.h"
#include "../concurrent/client_Looper.h"

#define KEY_DOWN GDK_KEY_Down
#define KEY_LEFT GDK_KEY_Left
#define KEY_RIGHT GDK_KEY_Right
#define KEY_SHOOT GDK_KEY_s
#define KEY_JUMP GDK_KEY_Up

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
