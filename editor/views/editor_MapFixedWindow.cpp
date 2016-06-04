/*
 * MapFixView.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: santi
 */

#include "editor_MapFixedWindow.h"

MapFixedWindow::MapFixedWindow() {
	// TODO Auto-generated constructor stub

}

MapFixedWindow::~MapFixedWindow() {
	// TODO Auto-generated destructor stub
}

MapFixedWindow::MapFixedWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Fixed(cobject), builder(refGlade) {

}
