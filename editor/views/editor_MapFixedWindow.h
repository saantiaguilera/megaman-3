/*
 * MapFixView.h
 *
 *  Created on: Jun 2, 2016
 *      Author: santi
 */

#ifndef EDITOR_VIEWS_EDITOR_MAPFIXEDWINDOW_H_
#define EDITOR_VIEWS_EDITOR_MAPFIXEDWINDOW_H_

#include <gtkmm.h>
#include "../models/editor_ObstacleViewContainer.h"
#include "../../common/common_MapView.h"

class MapFixedWindow : public Gtk::Fixed {
public:
	MapFixedWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
	MapFixedWindow();
	virtual ~MapFixedWindow();

	void setObstacleViewContainer(ObstacleViewContainer *obstacleViewContainer);
	void setMapView(MapView *aMapView);
	MapView *saveMapView();

	void removeAllChildViews();
	void removeObstacleContainerView(ObstacleViewContainer *obstacleViewContainer);
	void setBackgroundImage(std::string aBackgroundImagePath);

	ObstacleViewContainer *obstacleViewContainerWithPosition(int aX, int aY);

	int mapWidth();
	int mapHeight();

private :
    Glib::RefPtr<Gtk::Builder> builder;
    std::vector<ObstacleViewContainer *> *obstacleViewContainers;
    MapView *mapView;

    void cropMapBackground();


    Gtk::Image *backgroundImage;
};

#endif /* EDITOR_VIEWS_EDITOR_MAPFIXEDWINDOW_H_ */
