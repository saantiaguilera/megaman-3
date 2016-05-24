#ifndef CLIENT_CLIENT_CLIENT_H_
#define CLIENT_CLIENT_CLIENT_H_

#include <gtkmm.h>

#include "concurrent/client_Looper.h"
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
	Looper *connectionLooper = NULL;

	//Runs in main UI thread. Gets the FIFO event and responds to it or delegates
	virtual bool onMessageReceived();

	//Just calls onMessageReceived. Refactor and make the dispatcher call the onMessageReceived
	void onMessageFromDispatcher();

	//This method is thread safe (in the meaning that you can call it from wherever u want and you have guarantees that your event will be handled on the main ui only)
	virtual void onDataReceived();

	/* All the stuff he can do :) */
	void onCreateConnection(std::string ip);
	void onFlowToLobby();
	void onFlowToGame();
	void quit();

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
