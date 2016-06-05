/*
 * MainWindow.cpp
 *
 *  Created on: May 17, 2016
 *      Author: santi
 */

#include "editor_MainWindow.h"

#include "gtkmm.h"
#include <iostream>
#include "../controllers/editor_EditorController.h"
#include "../../common/common_MapViewParser.h"

//Constructors
MainWindow::MainWindow() {
}

MainWindow::~MainWindow() {
}

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), builder(refGlade){
    builder->get_widget("level1button", level1Button);
    builder->get_widget("level2button", level2Button);
    builder->get_widget("level3button", level3Button);
    builder->get_widget("level3button", level4Button);


    level1Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::level1ButtonWasTapped));
    level2Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::level2ButtonWasTapped));
    level3Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::level3ButtonWasTapped));
    level4Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::level4ButtonWasTapped));
}

//Setters
void MainWindow::setDelegate(EditorController *aDelegate) {
	delegate = aDelegate;
}


//Signals
void MainWindow::level1ButtonWasTapped(){
	std::cout<<"level 1 button was tapped"<<std::endl;

	MapViewParser mapParser;
	MapView *map = new MapView();


	mapParser.editorMapWithPath(map, "level1.json");

	delegate->presentMapWindowWithMap(map);
}

void MainWindow::level2ButtonWasTapped(){
	std::cout<<"level 2 button was tapped"<<std::endl;
}

void MainWindow::level3ButtonWasTapped(){
	std::cout<<"level 3 button was tapped"<<std::endl;
}

void MainWindow::level4ButtonWasTapped(){
	std::cout<<"level 4 button was tapped"<<std::endl;

	delegate->presentMainWindowWithoutSavingMap();
}



