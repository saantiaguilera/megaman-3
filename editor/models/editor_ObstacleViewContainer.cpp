/*
 * ObstacleViewContrainer.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: santi
 */

#include "editor_ObstacleViewContainer.h"

ObstacleViewContainer::ObstacleViewContainer(ObstacleViewType aType) {
	type = aType;

	image = new Gtk::Image(MapConstants().getImagePathWithObstacleViewType(type));
}

ObstacleViewContainer::ObstacleViewContainer() {}

ObstacleViewContainer::~ObstacleViewContainer() {}


Gtk::Image *ObstacleViewContainer::getImage() {
	image->show();

    image->set_size_request(kObstacleSize, kObstacleSize);

	return image;
}

