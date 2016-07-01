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
#include "../models/dialogs/editor_DialogManager.h"
#include "../../common/common_MapConstants.h"

//#define kObstacleSide 100
#define kLeftClickButton 1
#define kRightClickButton 3

MapWindow::MapWindow() {}

MapWindow::~MapWindow() {}

MapWindow::MapWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), builder(refGlade){
	maximize();

	//Navigation Buttons
	builder->get_widget("savebutton", saveButton);
    builder->get_widget("backbutton", backButton);

    builder->get_widget("blockbutton", blockButton);
    builder->get_widget("block1button", block1Button);
    builder->get_widget("block2button", block2Button);
    builder->get_widget("block3button", block3Button);

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

    builder->get_widget("background1button", background1Button);
    builder->get_widget("background2button", background2Button);
    builder->get_widget("background3button", background3Button);
    builder->get_widget("background4button", background4Button);

    //Window Buttons
    builder->get_widget("scrolledwindow", scrolledWindow);
    builder->get_widget_derived("fixedwindow", fixedWindow);
    override_background_color(Gdk::RGBA("gray"));
    builder->get_widget("eventbox", eventBox);

    builder->get_widget("bossbutton", bossButton);

    //Add scrolling effect to event box
    eventBox->add_events(Gdk::BUTTON_PRESS_MASK |
			   Gdk::BUTTON_RELEASE_MASK |
			   Gdk::SCROLL_MASK |
			   Gdk::SMOOTH_SCROLL_MASK |
			   Gdk::POINTER_MOTION_MASK);

    saveButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::saveButtonWasTapped));
    backButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::backButtonWasTapped));


    blockButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::blockButtonWasTapped));
    block1Button->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::block1ButtonWasTapped));
    block2Button->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::block2ButtonWasTapped));
    block3Button->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::block3ButtonWasTapped));

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
    bossButton->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::bossButtonWasTapped));
    background1Button->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::background1ButtonWasTapped));
    background2Button->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::background2ButtonWasTapped));
    background3Button->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::background3ButtonWasTapped));
    background4Button->signal_clicked().connect(sigc::mem_fun(* this, &MapWindow::background4ButtonWasTapped));


    int minHeight = 0;
    int minWidth = 0;

    get_size(minWidth, minHeight);

    int minHeightTruncated = minHeight + TERRAIN_TILE_SIZE - (minHeight % TERRAIN_TILE_SIZE);
    int minWidthTruncated = minWidth + TERRAIN_TILE_SIZE - (minWidth % TERRAIN_TILE_SIZE);

    fixedWindow->set_size_request(minWidthTruncated, minHeightTruncated);
}

//Signals
void MapWindow::saveButtonWasTapped() {
	DialogManager(this).showSaveDialog();
}

void MapWindow::saveMap() {
	MapView *savedMap = fixedWindow->saveMapView();

	savedMap->setHeight(fixedWindow->mapHeight());
	savedMap->setWidth(fixedWindow->mapWidth());

	fixedWindow->removeAllChildViews();

	delegate->presentMainWindowSavingMap(savedMap);
}

void MapWindow::saveMapWithBossType(ObstacleViewType bossType) {
	MapView *savedMap = fixedWindow->saveMapView();

	savedMap->setHeight(fixedWindow->mapHeight());
	savedMap->setWidth(fixedWindow->mapWidth());

	fixedWindow->removeAllChildViews();
	delegate->presentBossViewWithBossType(savedMap, bossType);
}

void MapWindow::back() {
	fixedWindow->removeAllChildViews();
	delegate->presentMainWindowWithoutSavingMap();
}

void MapWindow::backButtonWasTapped() {
	DialogManager(this).showBackDialog();

}
//Add Buttons
void MapWindow::blockButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeBlock);
}

void MapWindow::block1ButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeBlock1);
}

void MapWindow::block2ButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeBlock2);
}
void MapWindow::block3ButtonWasTapped() {
	addDraggingImageWithType(ObstacleViewTypeBlock3);
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
  std::cout << "add dragging image" << std::endl;

  if (draggingImage != NULL) {
    std::cout << "dragging image exists" << std::endl;

    deleteDraggingImage();
  }

	draggingBegin();

	ObstacleView *obstacleView = new ObstacleView(0, 0, obstacleViewType);

	draggingImageContainer = new ObstacleViewContainer(obstacleView);

	draggingImage = draggingImageContainer->getImage();
	draggingImage->hide();
	fixedWindow->setObstacleViewContainer(draggingImageContainer);
}

void MapWindow::bossButtonWasTapped() {
	if (bossEdition) {
		addDraggingImageWithType(bossType);
	} else {
//		DialogManager().showSaveDialogWithBossType(bossType);
	}

}

//Events
bool MapWindow::on_button_press_event(GdkEventButton *event) {
//		Have to delete tile
	if (event->button == kRightClickButton) {
//		Decide whether to remove while moving or static move
		if (draggingImageIsMoving) {
			deleteDraggingImage();
		} else {
			deleteImage(event->x, event->y);
		}

//		Have to add a new tile
	} else if (event->button == kLeftClickButton) {

//		Deside whether image have to be drop or just move it
		if (draggingImageIsMoving) {
			dropDraggingImage(event->x, event->y);
		} else {
			dragImage(event->x, event->y);
		}
	}

	resizeFixView();

	return true;
}

void MapWindow::resizeFixView() {
	int mapHeight = fixedWindow->mapHeight();
	int mapWidth = fixedWindow->mapWidth();

    int minHeight = 0;
    int minWidth = 0;

    scrolledWindow->get_size_request(minWidth, minHeight);

    int minHeightTruncated = minHeight + TERRAIN_TILE_SIZE - (minHeight % TERRAIN_TILE_SIZE);
    int minWidthTruncated = minWidth + TERRAIN_TILE_SIZE - (minWidth % TERRAIN_TILE_SIZE);

    mapHeight = minHeightTruncated > mapHeight ? minHeightTruncated : mapHeight;
    mapWidth= minWidthTruncated > mapWidth ? minWidthTruncated : mapWidth;


	fixedWindow->set_size_request(mapWidth +  3 * TERRAIN_TILE_SIZE,mapHeight + 3 * TERRAIN_TILE_SIZE);

}

void MapWindow::dropDraggingImage(int aX, int aY) {
	ObstacleViewContainer *obstacleViewContainer = fixedWindow->obstacleViewContainerWithPosition(aX, aY);

	if (obstacleViewContainer != NULL) {
		return;
	}

	draggingEnd();

	draggingImage = NULL;

	int x = aX - (aX % TERRAIN_TILE_SIZE);
	int y = aY - (aY % TERRAIN_TILE_SIZE);

	draggingImageContainer->getObstacleView()->setPosition(x, y);
	ObstacleViewType type = draggingImageContainer->getObstacleView()->getType();

	addDraggingImageWithType(type);
}

void MapWindow::dragImage(int aX, int aY) {
	draggingBegin();

	ObstacleViewContainer *obstacleViewContainer = fixedWindow->obstacleViewContainerWithPosition(aX, aY);

	if (obstacleViewContainer == NULL) {
		draggingEnd();
		return;
	}

	draggingImageContainer = obstacleViewContainer;

	draggingImage = draggingImageContainer->getImage();
}

void MapWindow::deleteDraggingImage() {
	draggingEnd();

	draggingImage = 0;
	fixedWindow->removeObstacleContainerView(draggingImageContainer);
}

void MapWindow::deleteImage(int aX, int aY) {
	ObstacleViewContainer *obstacleViewContainerToRemove = fixedWindow->obstacleViewContainerWithPosition(aX, aY);
	if (obstacleViewContainerToRemove == NULL) {
		return;
	}
	fixedWindow->removeObstacleContainerView(obstacleViewContainerToRemove);
}

bool MapWindow::on_motion_notify_event(GdkEventMotion* event) {
	int x = event->x;
	int y = event->y;

	if (draggingImageIsMoving) {
		draggingImage->show();
		fixedWindow->move(*draggingImage, x - (x % TERRAIN_TILE_SIZE), y - (y % TERRAIN_TILE_SIZE));
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
	fixedWindow->setMapView(aMapView);

	resizeFixView();
}

void MapWindow::setDelegate(EditorController *aDelegate) {
	delegate = aDelegate;
}

void MapWindow::setBossType(ObstacleViewType aBossType, bool isBossEditable) {
	bossType = aBossType;
	bossEdition = isBossEditable;
	// Megaman is not a boss (this is awful but i am having lot of trouble)

	bossButton->show();

	Gtk::Image *image = new Gtk::Image(MapConstants().getImagePathWithObstacleViewType(bossType));

	bossButton->set_image(*image);
}

void MapWindow::background1ButtonWasTapped() {
	fixedWindow->setBackgroundImage("res/drawable/background/background1.png");
}

void MapWindow::background2ButtonWasTapped() {
	fixedWindow->setBackgroundImage("res/drawable/background/background2.png");
}

void MapWindow::background3ButtonWasTapped() {
	fixedWindow->setBackgroundImage("res/drawable/background/background3.png");
}

void MapWindow::background4ButtonWasTapped() {
	fixedWindow->setBackgroundImage("res/drawable/background/background4.png");
}
