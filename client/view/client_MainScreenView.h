#ifndef CLIENT_MAINSCREENVIEW_H_
#define CLIENT_MAINSCREENVIEW_H_

#include <gtkmm.h>

#include "../../Constants.h"

/**
 * Simple interface, nothing weird to comment about it
 */
class OnEnterPressedInterface {
  public:
    virtual void onEnterPressed(std::string ipport, std::string name) = 0;
};

class MainScreenView : public Gtk::Window {
private:
    Gtk::Entry *ipText = nullptr;
    Gtk::Entry *nameText = nullptr;
    Gtk::Spinner *progressBar = nullptr;
    Gtk::Label *resultText = nullptr;

    OnEnterPressedInterface *callback = NULL;

    /**
     * Simple method that justs dispatches to the interface if exists
     * Else its default behaviour its nothing
     */
    void onEnterPressed(Gtk::Entry *editText);

    void setProgressBarIndeterminate(bool active);

public:
  MainScreenView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

  virtual ~MainScreenView();

  /**
   * Setter if someone wants to do something about the Enter pressing
   */
  void setEnterPressedListener(OnEnterPressedInterface *listener);

  void setResult(ConnectionResult result);
};

#endif
