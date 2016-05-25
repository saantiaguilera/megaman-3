#ifndef CLIENT_RECEIVERCONTRACT_H_
#define CLIENT_RECEIVERCONTRACT_H_

class ReceiverContract {
public:
  virtual ~ReceiverContract() {};
  virtual void onDataReceived() = 0;
};

#endif
