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


   	//signal handlers
    void backButtonWasTapped();
    void saveButtonWasTapped();
};

#endif /* EDITOR_VIEWS_EDITOR_MAPWINDOW_H_ */
