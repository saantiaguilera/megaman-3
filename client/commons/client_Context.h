#ifndef CLIENT_CLIENT_CONTEXT_H_
#define CLIENT_CLIENT_CONTEXT_H_

class Context : public Handler {
public:
	virtual ~Context();
	virtual void attachController(Controller *controller) = 0;
	virtual bool onMessageReceived() = 0;
};

#endif
