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
  builder->get_widget("level4button", level4Button);
  builder->get_widget("level5button", level5Button);

  builder->get_widget("bosschamber1button", bossChamber1Button);
  builder->get_widget("bosschamber2button", bossChamber2Button);
  builder->get_widget("bosschamber3button", bossChamber3Button);
  builder->get_widget("bosschamber4button", bossChamber4Button);
  builder->get_widget("bosschamber5button", bossChamber5Button);


  level1Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::level1ButtonWasTapped));
  level2Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::level2ButtonWasTapped));
  level3Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::level3ButtonWasTapped));
  level4Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::level4ButtonWasTapped));
  level5Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::level5ButtonWasTapped));


  bossChamber1Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::bossChamber1ButtonWasTapped));
  bossChamber2Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::bossChamber2ButtonWasTapped));
  bossChamber3Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::bossChamber3ButtonWasTapped));
  bossChamber4Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::bossChamber4ButtonWasTapped));
  bossChamber5Button->signal_clicked().connect(sigc::mem_fun(* this, &MainWindow::bossChamber5ButtonWasTapped));

}

//Setters
void MainWindow::setDelegate(EditorController *aDelegate) {
	delegate = aDelegate;
}


//Signals
void MainWindow::level1ButtonWasTapped(){
	presentMapWindowWithMapName("level1.json");
}

void MainWindow::level2ButtonWasTapped(){
	presentMapWindowWithMapName("level2.json");
}

void MainWindow::level3ButtonWasTapped(){
	presentMapWindowWithMapName("level3.json");
}

void MainWindow::level4ButtonWasTapped(){
	presentMapWindowWithMapName("level4.json");
}

void MainWindow::level5ButtonWasTapped(){
	presentMapWindowWithMapName("level5.json");
}

void MainWindow::bossChamber1ButtonWasTapped(){
	presentMapWindowWithMapName("bosschamber1.json");
}

void MainWindow::bossChamber2ButtonWasTapped(){
	presentMapWindowWithMapName("bosschamber2.json");
}

void MainWindow::bossChamber3ButtonWasTapped(){
	presentMapWindowWithMapName("bosschamber3.json");
}

void MainWindow::bossChamber4ButtonWasTapped(){
	presentMapWindowWithMapName("bosschamber4.json");
}

void MainWindow::bossChamber5ButtonWasTapped(){
	presentMapWindowWithMapName("bosschamber5.json");
}

void MainWindow::presentMapWindowWithMapName(std::string mapName) {
	MapViewParser mapParser;
	MapView *map = new MapView();

	mapParser.editorMapWithPath(map, mapName);

	delegate->presentMapWindowWithMap(map);
}

void MainWindow::presentMapWithBossType(ObstacleViewType aBossType) {
	std::cout<<aBossType<<std::endl;

}
