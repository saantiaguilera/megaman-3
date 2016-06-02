/*
 * MapWindow.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_VIEWS_EDITOR_MAPWINDOW_H_
#define EDITOR_VIEWS_EDITOR_MAPWINDOW_H_

#include <gtkmm.h>
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

    //Different Buttons
    Gtk::Button *backButton;
    Gtk::Button *saveButton;
    Gtk::EventBox *eventBox;
    Gtk::ScrolledWindow *scrolledWindow;
    Gtk::Fixed *layoutWindow;

    Gtk::Button *blockButton;


    // Override mouse events
    bool on_button_press_event(GdkEventButton *event);
	bool on_motion_notify_event(GdkEventMotion*event);

   	//signal handlers
    void backButtonWasTapped();
    void saveButtonWasTapped();


    void blockButtonWasTapped();

};

#endif /* EDITOR_VIEWS_EDITOR_MAPWINDOW_H_ */
