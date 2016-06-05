#include <iostream>

#include "client_MainScreenView.h"

#define PATH_HOME_SCREEN_EDIT_TEXT_VIEW "client_home_screen_edit_text"
#define PATH_HOME_SCREEN_PROGRESS_BAR_VIEW "client_home_screen_progress_bar"
#define PATH_HOME_SCREEN_RESULT_TEXT_VIEW "client_home_screen_result_text_view"
#define PATH_HOME_SCREEN_NAME_TEXT_VIEW "client_home_screen_name_text"

MainScreenView::MainScreenView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) :
          Gtk::Window(cobject) {
    refBuilder->get_widget(PATH_HOME_SCREEN_EDIT_TEXT_VIEW, ipText);
    refBuilder->get_widget(PATH_HOME_SCREEN_PROGRESS_BAR_VIEW, progressBar);
    refBuilder->get_widget(PATH_HOME_SCREEN_RESULT_TEXT_VIEW, resultText);
    refBuilder->get_widget(PATH_HOME_SCREEN_NAME_TEXT_VIEW, nameText);

    if(ipText)
      ipText->signal_activate().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this, &MainScreenView::onEnterPressed), ipText));
}

MainScreenView::~MainScreenView() {
}

void MainScreenView::setResult(ConnectionResult result) {
    switch (result) {
      case RESULT_OK:
        setProgressBarIndeterminate(false);
        resultText->set_text("CONNECTED");
        resultText->override_color(Gdk::RGBA("green"), Gtk::STATE_FLAG_NORMAL);
        break;

      case RESULT_INDETERMINATE:
        setProgressBarIndeterminate(true);
        resultText->set_text("");
        break;

      case RESULT_ERROR:
        setProgressBarIndeterminate(false);
        resultText->set_text("AN ERROR HAS OCCURED. PLS TRY AGAIN");
        resultText->override_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
    }
  }

void MainScreenView::setEnterPressedListener(OnEnterPressedInterface *listener) {
    callback = listener;
  }

void MainScreenView::onEnterPressed(Gtk::Entry *editText) {
  if (callback)
    callback->onEnterPressed(editText->get_text(), nameText->get_text());
}

void MainScreenView::setProgressBarIndeterminate(bool active) {
  if (active)
    progressBar->start();
  else progressBar->stop();
}
