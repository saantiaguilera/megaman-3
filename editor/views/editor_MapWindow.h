/*
 * MapWindow.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_VIEWS_EDITOR_MAPWINDOW_H_
#define EDITOR_VIEWS_EDITOR_MAPWINDOW_H_

#include <gtkmm.h>

#include "editor_MapFixedWindow.h"
#include "obstacles/editor_ObstacleView.h"

class EditorController;


class MapWindow : public Gtk::Window {
public:
	//Constructors
    MapWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);

	MapWindow();
	virtual ~MapWindow();

protected:
	//Needed to upload xml from GLADE
    Glib::RefPtr<Gtk::Builder> builder;

    //Delegate
    EditorController *delegate;

    Gtk::Image *draggingImage;

    //Navigation Buttons
    Gtk::Button *backButton;
    Gtk::Button *saveButton;

    //Add Buttons
    Gtk::Button *blockButton;
    Gtk::Button *needleButton;
    Gtk::Button *precipiceButton;
    Gtk::Button *spawnButton;
    std::vector<Gtk::Button *> *addButtonVector;
    void addButtonWithName(Gtk::Button *aButton, std::string aName);

    //Window Buttons
    Gtk::EventBox *eventBox;
    Gtk::ScrolledWindow *scrolledWindow;
    MapFixedWindow *fixedWindow;

    // Override mouse events
    bool on_button_press_event(GdkEventButton *event);
	bool on_motion_notify_event(GdkEventMotion*event);

   	//Signal handlers
    void backButtonWasTapped();
    void saveButtonWasTapped();

    //Add Button Signals
    void blockButtonWasTapped();
    void needleButtonWasTapped();
    void precipiceButtonWasTapped();
    void spawnButtonWasTapped();

private:
    bool draggingImageIsMoving = false;
    void draggingBegin();
    void draggingEnd();
};

#endif /* EDITOR_VIEWS_EDITOR_MAPWINDOW_H_ */
