/*
 * MapWindow.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "editor_MapWindow.h"

#include "../controllers/editor_EditorController.h"
#include <iostream>
#include <exception>


#define kObstacleSize 100
#define kWindowsPadding 20
#define kMaxAddButtonHeight 500

MapWindow::MapWindow() {
	// TODO Auto-generated constructor stub

}

MapWindow::~MapWindow() {
	delete addButtonVector;
}

MapWindow::MapWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), builder(refGlade){
	maximize();

	//Navigation Buttons
	builder->get_widget("savebutton", saveButton);
    builder->get_widget("backbutton", backButton);

    builder->get_widget("blockbutton", blockButton);
    builder->get_widget("needlebutton", needleButton);
    builder->get_widget("precipicebutton", precipiceButton);
    builder->get_widget("spawnbutton", spawnButton);

    //Window Buttons
    builder->get_widget("scrolledwindow", scrolledWindow);
    builder->get_widget_derived("fixedwindow", fixedWindow);
    builder->get_widget("eventbox", eventBox);


    //Add scrolling effect to event box
    eventBox->add_events(Gdk::BUTTON_PRESS_MASK |
			   Gdk::BUTTON_RELEASE_MASK |
			   Gdk::SCROLL_MASK |
			   Gdk::SMOOTH_SCROLL_MASK |
			   Gdk::POINTER_MOTION_MASK);

    saveButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::saveButtonWasTapped));
    backButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::backButtonWasTapped));
    blockButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::blockButtonWasTapped));
    needleButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::needleButtonWasTapped));
    precipiceButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::precipiceButtonWasTapped));
    spawnButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::spawnButtonWasTapped));

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

//Add Buttons
void MapWindow::blockButtonWasTapped() {
	draggingBegin();
	Gdk::Pixbuf::create_from_file("./res/drawable/blocks/block_grass.png");
	draggingImage = new Gtk::Image("./res/drawable/blocks/block_grass.png");
	draggingImage->show();

    draggingImage->set_size_request(kObstacleSize, kObstacleSize);
    fixedWindow->put(*draggingImage, 0, 0);
}

void MapWindow::needleButtonWasTapped() {
	draggingBegin();
	Gdk::Pixbuf::create_from_file("./res/drawable/blocks/block_grass.png");
	draggingImage = new Gtk::Image("./res/drawable/blocks/block_grass.png");
	draggingImage->show();

    draggingImage->set_size_request(kObstacleSize, kObstacleSize);
    fixedWindow->put(*draggingImage, 0, 0);
}

void MapWindow::precipiceButtonWasTapped() {
	draggingBegin();
	Gdk::Pixbuf::create_from_file("./res/drawable/blocks/block_grass.png");
	draggingImage = new Gtk::Image("./res/drawable/blocks/block_grass.png");
	draggingImage->show();

    draggingImage->set_size_request(kObstacleSize, kObstacleSize);
    fixedWindow->put(*draggingImage, 0, 0);
}

void MapWindow::spawnButtonWasTapped() {
	draggingBegin();
	Gdk::Pixbuf::create_from_file("./res/drawable/blocks/block_grass.png");
	draggingImage = new Gtk::Image("./res/drawable/blocks/block_grass.png");
	draggingImage->show();

    draggingImage->set_size_request(kObstacleSize, kObstacleSize);
    fixedWindow->put(*draggingImage, 0, 0);
}

//Events
bool MapWindow::on_button_press_event(GdkEventButton *event) {
	draggingEnd();

	draggingImage = 0;

	int x = event->x;
	int y = event->y;


	std::cout<<x<<y<<std::endl;

	return true;
}

bool MapWindow::on_motion_notify_event(GdkEventMotion* event) {
	int x = event->x;
	int y = event->y;

	std::cout<<"x in event box : "<<x<<"y in event box : "<<y<<std::endl;
	if (draggingImageIsMoving) {
		fixedWindow->move(*draggingImage, x - (x % kObstacleSize), y - (y % kObstacleSize));
	}

	return true;
}

void MapWindow::draggingBegin() {
	draggingImageIsMoving = true;
}

void MapWindow::draggingEnd() {
	draggingImageIsMoving = false;
}
