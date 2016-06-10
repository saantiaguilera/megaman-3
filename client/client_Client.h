#ifndef CLIENT_CLIENT_CLIENT_H_
#define CLIENT_CLIENT_CLIENT_H_

#include <gtkmm.h>

#include "concurrent/client_Looper.h"
#include "controller/concurrent/client_ConnectionThread.h"
#include "controller/concurrent/client_ReceiverContract.h"
#include "controller/concurrent/client_ReceiverThread.h"
#include "controller/concurrent/client_SenderThread.h"
#include "../common/common_Socket.h"
#include "commons/client_Context.h"
#include "commons/client_Controller.h"

/**
 * Pasar a cpp
 */
class Client : public Context, private ReceiverContract {
private:
	std::string clientName;

	Glib::RefPtr<Gtk::Application> app;

	Controller *currentController;

	Glib::Dispatcher dispatcher;

	//For creating the initial connection
	Socket *socket = NULL;
  ConnectionThread *connectionThread = NULL;

	//For sending local events to server
	SenderThread *senderThread = NULL;
	Looper *senderLooper = NULL;

	//For receiving data from server
	ReceiverThread *receiverThread = NULL;

	//Runs in main UI thread. Gets the FIFO event and responds to it or delegates
	virtual bool onMessageReceived();

	//Just calls onMessageReceived. Refactor and make the dispatcher call the onMessageReceived
	void onMessageFromDispatcher();

	//This method is thread safe (in the meaning that you can call it from wherever u want and you have guarantees that your event will be handled on the main ui only)
	virtual void onDataReceived();

	/* All the stuff he can do :) */
	void onCreateConnection(std::string ip, std::string name);
	void onFlowToLobby();
	void onFlowToGame();
	void onFlowToStart();
	void createSenderAndReceiver();

public:
	Client();

	virtual ~Client();

	virtual void attachController(Controller *controller);

	void start(int argc, char *argv[]);

private:
	Client(const Client&);
	Client& operator=(const Client&);
};

#endif /* CLIENT_CLIENT_CLIENT_H_ */
