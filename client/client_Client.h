#ifndef CLIENT_CLIENT_CLIENT_H_
#define CLIENT_CLIENT_CLIENT_H_

/**
 * Pasar a cpp
 */
class Client : public Context, private ReceiverContract {
private:
	Controller *currentController;

	Glib::Dispatcher dispatcher;
  ConnectionThread *connectionThread = NULL;

	virtual bool onMessageReceived();

	virtual void onDataReceived();

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
