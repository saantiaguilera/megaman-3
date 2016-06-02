/*
 * MapWindow.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "editor_MapWindow.h"

#include "../controllers/editor_EditorController.h"
#include <iostream>

MapWindow::MapWindow() {
	// TODO Auto-generated constructor stub

}

MapWindow::~MapWindow() {
	// TODO Auto-generated destructor stub
}

MapWindow::MapWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), builder(refGlade){

	//Get save, back and event
	builder->get_widget("savebutton", saveButton);
    builder->get_widget("backbutton", backButton);
    builder->get_widget("eventbox", eventBox);
    builder->get_widget("blockbutton", blockButton);
    builder->get_widget("scrolledwindow", scrolledWindow);
    builder->get_widget("layoutwindow", layoutWindow);


    //Add scrolling effect to event box
    eventBox->add_events(Gdk::BUTTON_PRESS_MASK |
			   Gdk::BUTTON_RELEASE_MASK |
			   Gdk::SCROLL_MASK |
			   Gdk::SMOOTH_SCROLL_MASK |
			   Gdk::POINTER_MOTION_MASK);

    saveButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::saveButtonWasTapped));
    backButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::backButtonWasTapped));


    blockButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::blockButtonWasTapped));
}

//Signals
void MapWindow::saveButtonWasTapped() {
//	delegate->presentMainWindowWithoutSavingMap();
	std::cout<<"Save button"<<std::endl;
}

void MapWindow::backButtonWasTapped() {
//	delegate->presentMainWindowWithoutSavingMap();
	std::cout<<"Back button"<<std::endl;
}

void MapWindow::blockButtonWasTapped() {
	builder->get_widget("image2", draggingImage);

	draggingImage->set_size_request(100, 100);

	std::cout<<draggingImage<<std::endl;

	layoutWindow->add(*draggingImage);
}

//Events
bool MapWindow::on_button_press_event(GdkEventButton *event) {
	int x = event->x;
	int y = event->y;
	std::cout<<"x in event box : "<<x<<"y in event box : "<<y<<std::endl;
	std::cout<<"aguantaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<std::endl;
	return true;
}

bool MapWindow::on_motion_notify_event(GdkEventMotion* event) {
	int x = event->x;
	int y = event->y;

	std::cout<<"x in event box : "<<x<<"y in event box : "<<y<<std::endl;

	layoutWindow->move(*draggingImage, x, y);

	draggingImage->set_alignment(x, y);

	return true;
}

