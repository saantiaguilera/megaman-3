/*
 * MainWindow.cpp
 *
 *  Created on: May 17, 2016
 *      Author: santi
 */

#include "editor_MainWindow.h"

#include "gtkmm.h"
#include "iostream"

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


    level1Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::on_level1_button_clicked));
    level2Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::on_level2_button_clicked));
    level3Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::on_level3_button_clicked));
    level4Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::on_level4_button_clicked));
}


void MainWindow::on_level1_button_clicked(){
	std::cout<<"level 1 button was tapped"<<std::endl;
}

void MainWindow::on_level2_button_clicked(){
	std::cout<<"level 2 button was tapped"<<std::endl;
}

void MainWindow::on_level3_button_clicked(){
	std::cout<<"level 3 button was tapped"<<std::endl;
}

void MainWindow::on_level4_button_clicked(){
	std::cout<<"level 4 button was tapped"<<std::endl;
}



