/*
 * ObstacleViewContrainer.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: santi
 */

#include "editor_ObstacleViewContainer.h"

#include "../../common/common_MapConstants.h"
#include <iostream>

ObstacleViewContainer::ObstacleViewContainer(ObstacleView *aObstacleView) {
	obstacleView = aObstacleView;

	ObstacleViewType type = obstacleView->getType();

	Glib::RefPtr<Gdk::Pixbuf> temp = Gdk::Pixbuf::create_from_file(MapConstants().getImagePathWithObstacleViewType(type));
	temp =  temp->scale_simple(TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE, Gdk::INTERP_BILINEAR);

	image = new Gtk::Image();
	image->set(temp);
}

ObstacleViewContainer::ObstacleViewContainer() {}

ObstacleViewContainer::~ObstacleViewContainer() {
	delete image;
}


Gtk::Image *ObstacleViewContainer::getImage() {
	if (!isShowing) {
		image->show();
		image->set_size_request(TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE);
		isShowing = !isShowing;
	}

	return image;
}

ObstacleView *ObstacleViewContainer::getObstacleView() {
	return obstacleView;
}
