/*
 * MapWindow.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "editor_MapWindow.h"

#include "../controllers/editor_EditorController.h"

MapWindow::MapWindow() {
	// TODO Auto-generated constructor stub

}

MapWindow::~MapWindow() {
	// TODO Auto-generated destructor stub
}

MapWindow::MapWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), builder(refGlade){
    builder->get_widget("savebutton", saveButton);
    builder->get_widget("backbutton", backButton);
//    builder->get_widget("level2button", level2Button);
//    builder->get_widget("level3button", level3Button);
//    builder->get_widget("level3button", level4Button);
//
//
    saveButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::saveButtonWasTapped));
    backButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::backButtonWasTapped));
//    level2Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::on_level2_button_clicked));
//    level3Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::on_level3_button_clicked));
//    level4Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::on_level4_button_clicked));
}

//Signals
void MapWindow::saveButtonWasTapped() {
	delegate->presentMainWindowWithoutSavingMap();
}

void MapWindow::backButtonWasTapped() {
	delegate->presentMainWindowWithoutSavingMap();
}

