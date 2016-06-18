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
#define KEY_WEAPON_1 GDK_KEY_1
#define KEY_WEAPON_2 GDK_KEY_2
#define KEY_WEAPON_3 GDK_KEY_3
#define KEY_WEAPON_4 GDK_KEY_4
#define KEY_WEAPON_5 GDK_KEY_5
#define KEY_WEAPON_6 GDK_KEY_6

class GameController : public Controller, private OnKeyPressListener {
private:
  GameView *view;

  KeyMap keyMap;

  virtual bool onMessageReceived();
  virtual bool onKeyPressEvent(GdkEventKey *event);
  bool shouldSendKeyMap(int key);

public:
  virtual Gtk::Window * getView();
  virtual void setVisibility(bool visible);

  virtual ~GameController();
  GameController(Context *context);
};

#endif
