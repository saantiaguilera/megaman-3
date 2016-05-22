#ifndef CLIENT_CLIENT_LOBBYCONTROLLER_H_
#define CLIENT_CLIENT_LOBBYCONTROLLER_H_

#include <gtkmm.h>
#include "../commons/client_Context.h"
#include "../commons/client_Controller.h"
#include "../view/client_LobbyView.h"

class LobbyController : public Controller {
private:
  LobbyView *view;

  virtual bool onMessageReceived();

public:
  virtual Gtk::Window * getView();
  virtual void setVisibility(bool visible);

  virtual ~LobbyController();
  LobbyController(Context *context);
};

#endif
