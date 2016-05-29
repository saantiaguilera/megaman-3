/*
 * MainWindow.h
 *
 *  Created on: May 17, 2016
 *      Author: santi
 */

#ifndef EDITOR_VIEWS_EDITOR_MAINWINDOW_H_
#define EDITOR_VIEWS_EDITOR_MAINWINDOW_H_

#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
	//Constructors
    MainWindow();
    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);//constructor

	//Destructors
	virtual ~MainWindow();
protected:
	//Needed to upload xml from GLADE
    Glib::RefPtr<Gtk::Builder> builder;

    //Different Buttons
    Gtk::Button *level1Button;
    Gtk::Button *level2Button;
    Gtk::Button *level3Button;
    Gtk::Button *level4Button;


   	//signal handlers
    void on_level1_button_clicked();
    void on_level2_button_clicked();
    void on_level3_button_clicked();
    void on_level4_button_clicked();
};


#endif /* EDITOR_VIEWS_EDITOR_MAINWINDOW_H_ */
