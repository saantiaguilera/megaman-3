#ifndef CLIENT_CLIENT_CLIENT_H_
#define CLIENT_CLIENT_CLIENT_H_

#include <gtkmm.h>

#include "controller/concurrent/client_ConnectionThread.h"
#include "commons/client_Context.h"
#include "commons/client_Controller.h"

/**
 * Pasar a cpp
 */
class Client : public Context, private ReceiverContract {
private:
	Glib::RefPtr<Gtk::Application> app;

	Controller *currentController;

	Glib::Dispatcher dispatcher;
  ConnectionThread *connectionThread = NULL;

	virtual bool onMessageReceived();
	void onMessageFromDispatcher();

	virtual void onDataReceived();

	/* All the stuff he can do :) */
	void onCreateConnection(std::string ip);
	void onFlowToLobby();
	void onFlowToGame();

public:
	Client();

	virtual ~Client();

	virtual void attachController(Controller *controller);

	void start();

private:
	Client(const Client&);
	Client& operator=(const Client&);
};

#endif /* CLIENT_CLIENT_CLIENT_H_ */
