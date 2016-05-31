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


class MapWindow : public Gtk::Window{
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

    //Different Buttons
    Gtk::Button *backButton;
    Gtk::Button *saveButton;
    Gtk::EventBox *eventBox;

    // Override mouse events
    bool on_button_press_event(GdkEventButton *event);
    bool motion_notify_event( GtkWidget *widget, GdkEventMotion *event );


   	//signal handlers
    void backButtonWasTapped();
    void saveButtonWasTapped();
};

#endif /* EDITOR_VIEWS_EDITOR_MAPWINDOW_H_ */
