/*
 * MapFixView.h
 *
 *  Created on: Jun 2, 2016
 *      Author: santi
 */

#ifndef EDITOR_VIEWS_EDITOR_MAPFIXEDWINDOW_H_
#define EDITOR_VIEWS_EDITOR_MAPFIXEDWINDOW_H_

#include <gtkmm.h>

//#include "obstacles/editor_ObstacleView.h"

class MapFixedWindow : public Gtk::Fixed {
public:
	MapFixedWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
	MapFixedWindow();
	virtual ~MapFixedWindow();

private :
    Glib::RefPtr<Gtk::Builder> builder;
//    std::vector<ObstacleView *> *obstacleViews;
};

#endif /* EDITOR_VIEWS_EDITOR_MAPFIXEDWINDOW_H_ */
