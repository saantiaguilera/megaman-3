#ifndef CLIENT_CLIENT_HANDLER_H_
#define CLIENT_CLIENT_HANDLER_H_

class Handler {
public:
	virtual ~Handler() {}
	virtual bool onMessageReceived() = 0; //Returns if consumed or not
};

#endif
