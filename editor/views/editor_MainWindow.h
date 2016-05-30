/*
 * MainWindow.h
 *
 *  Created on: May 17, 2016
 *      Author: santi
 */

#ifndef EDITOR_VIEWS_EDITOR_MAINWINDOW_H_
#define EDITOR_VIEWS_EDITOR_MAINWINDOW_H_

#include <gtkmm.h>
class EditorController;

class MainWindow : public Gtk::Window {
public:
	//Constructors
    MainWindow();
    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);//constructor

    //Setters
    void setDelegate(EditorController *aDelegate);

	//Destructors
	virtual ~MainWindow();
protected:
	//Needed to upload xml from GLADE
    Glib::RefPtr<Gtk::Builder> builder;

    //Delegate
    EditorController *delegate;

    //Different Buttons
    Gtk::Button *level1Button;
    Gtk::Button *level2Button;
    Gtk::Button *level3Button;
    Gtk::Button *level4Button;


   	//signal handlers
    void level1ButtonWasTapped();
    void level2ButtonWasTapped();
    void level3ButtonWasTapped();
    void level4ButtonWasTapped();
};


#endif /* EDITOR_VIEWS_EDITOR_MAINWINDOW_H_ */
