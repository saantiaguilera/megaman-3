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
#include "../models/editor_ObstacleViewContainer.h"

#define kObstacleSide 100

MapWindow::MapWindow() {}

MapWindow::~MapWindow() {}

MapWindow::MapWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), builder(refGlade){
	maximize();

	//Navigation Buttons
	builder->get_widget("savebutton", saveButton);
    builder->get_widget("backbutton", backButton);

    builder->get_widget("blockbutton", blockButton);
    builder->get_widget("needlebutton", needleButton);
    builder->get_widget("ladderbutton", ladderButton);
    builder->get_widget("precipicebutton", precipiceButton);
    builder->get_widget("bosschaimberbutton", bossChamberButton);

    builder->get_widget("megamanspawnbutton", megamanSpawnButton);
    builder->get_widget("bumpyspawnbutton", bumpySpawnButton);
    builder->get_widget("jumpingsniperspawnbutton", jumpingSniperSpawnButton);
    builder->get_widget("metspawnbutton", metSpawnButton);
    builder->get_widget("normalsniperspawnbutton", normalSniperSpawnButton);

    builder->get_widget("lifebutton", lifeButton);
    builder->get_widget("energysmallbutton", energySmallButton);
    builder->get_widget("energybigbutton", energyBigButton);
    builder->get_widget("bigammobutton", bigAmmoButton);
    builder->get_widget("smallammobutton", smallAmmoButton);

    //SpinButons
    builder->get_widget("heightspinbutton", heightSpinButton);
    builder->get_widget("widthspinbutton", widthSpinButton);


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
    ladderButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::ladderButtonWasTapped));
    bossChamberButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::bossChamberButtonWasTapped));
    megamanSpawnButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::megamanSpawnButtonWasTapped));
    bumpySpawnButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::bumpySpawnButtonWasTapped));
    jumpingSniperSpawnButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::jumpingSniperSpawnButtonWasTapped));
    metSpawnButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::metSpawnButtonWasTapped));
    normalSniperSpawnButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::normalSniperSpawnButtonWasTapped));
    lifeButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::lifeButtonWasTapped));
    energySmallButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::energySmallButtonWasTapped));
    energyBigButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::energyBigButtonWasTapped));
    bigAmmoButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::bigAmmoButtonWasTapped));
    smallAmmoButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::smallAmmoButtonWasTapped));

    //Spin Buttons
    int minHeight = 0;
    int minWidth = 0;

    get_size(minWidth, minHeight);

    int minHeightTruncated = minHeight + kObstacleSide - (minHeight % kObstacleSide);
    int minWidthTruncated = minWidth + kObstacleSide - (minWidth % kObstacleSide);

    heightSpinButton->set_range(minHeightTruncated, kObstacleSide * 1000);
    widthSpinButton->set_range(minWidthTruncated, kObstacleSide * 1000);

    heightSpinButton->set_numeric(true);
    widthSpinButton->set_numeric(true);
    heightSpinButton->set_increments(100, 100);
    widthSpinButton->set_increments(100, 100);

    fixedWindow->set_size_request(minWidthTruncated, minHeightTruncated);

    heightSpinButton->signal_value_changed().connect(sigc::mem_fun(* this, &MapWindow::sizeDidModify));
    widthSpinButton->signal_value_changed().connect(sigc::mem_fun(* this, &MapWindow::sizeDidModify));

}

//Signals
void MapWindow::saveButtonWasTapped() {
	MapView *savedMap = fixedWindow->saveMapView();
	delegate->presentMainWindowSavingMap(savedMap);
}

void MapWindow::backButtonWasTapped() {
	delegate->presentMainWindowWithoutSavingMap();
}

//Add Buttons
void MapWindow::blockButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeBlock);
}

void MapWindow::needleButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeNeedle);
}

void MapWindow::precipiceButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypePrecipice);
}
void MapWindow::ladderButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeLadder);
}

void MapWindow::bossChamberButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeBossChamberGate);
}

    //Spawns
void MapWindow::megamanSpawnButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeMegaman);
}

void MapWindow::bumpySpawnButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeBumpy);
}

void MapWindow::jumpingSniperSpawnButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeJumpingSnyper);
}

void MapWindow::metSpawnButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeMet);
}

void MapWindow::normalSniperSpawnButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeNormalSnyper);
}


    //Powerups
void MapWindow::lifeButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeLife);
}

void MapWindow::energySmallButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeSmallEnergyCapsule);
}

void MapWindow::energyBigButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeBigEnergyCapsule);
}

void MapWindow::bigAmmoButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeBigAmmoPack);
}

void MapWindow::smallAmmoButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeSmallAmmoPack);
}

void MapWindow::addDraggingImageWithType(ObstacleViewType obstacleViewType) {
	draggingBegin();

	ObstacleView *obstacleView = new ObstacleView(0, 0, obstacleViewType);

	draggingImageContainer = new ObstacleViewContainer(obstacleView);


	draggingImage = draggingImageContainer->getImage();
	fixedWindow->setObstacleViewContainer(draggingImageContainer);
}

//Size
void MapWindow::sizeDidModify() {
	int height = heightSpinButton->get_value_as_int();
	int width = widthSpinButton->get_value_as_int();

	fixedWindow->set_size_request(width, height);
}

//Events
bool MapWindow::on_button_press_event(GdkEventButton *event) {
	draggingEnd();

	draggingImage = 0;

	int x = event->x;
	int y = event->y;

	x = x - (x % kObstacleSize);
	y = y - (y % kObstacleSize);

	draggingImageContainer->getObstacleView()->setPosition(x, y);

	return true;
}

bool MapWindow::on_motion_notify_event(GdkEventMotion* event) {
	int x = event->x;
	int y = event->y;

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

//Setters
void MapWindow::setMapView(MapView *aMapView) {
	heightSpinButton->set_value(aMapView->getHeight());
	widthSpinButton->set_value(aMapView->getWidth());
	sizeDidModify();

	fixedWindow->setMapView(aMapView);
}

void MapWindow::setDelegate(EditorController *aDelegate) {
	delegate = aDelegate;
}
