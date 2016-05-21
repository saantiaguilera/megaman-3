#ifndef CLIENT_CLIENT_CONTROLLER_H_
#define CLIENT_CLIENT_CONTROLLER_H_

class Controller : public Handler {
private:
  Context *context;

protected:
  Context * getContext();

public:
  Controller(Context *ctx);

  virtual ~Controller();
  virtual bool onMessageReceived() = 0;

  virtual void setVisibility(bool visible) = 0;
  virtual Gtk::Window * getView() = 0;
};

#endif
