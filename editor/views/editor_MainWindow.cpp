/*
 * MainWindow.cpp
 *
 *  Created on: May 17, 2016
 *      Author: santi
 */

#include "editor_MainWindow.h"

#include "gtkmm.h"

using namespace Gtk;

MainWindow::MainWindow() {
}

MainWindow::~MainWindow() {
}


MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), builder(refGlade){

    builder->get_widget("btnOk", btnOk);
    builder->get_widget("btnCancel", btnCancel);
    builder->get_widget("lblNotice",lblNotice);

    btnOk->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::on_ok_button_clicked));
    btnCancel->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_cancel_button_clicked));
}


void MainWindow::on_ok_button_clicked(){
    lblNotice->set_text("OK clicked");
}

void MainWindow::on_cancel_button_clicked(){
    lblNotice->set_text("Cancel clicked");
}
