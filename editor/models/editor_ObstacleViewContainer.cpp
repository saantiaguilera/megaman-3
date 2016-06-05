/*
 * ObstacleViewContrainer.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: santi
 */

#include "editor_ObstacleViewContainer.h"

#include <iostream>

ObstacleViewContainer::ObstacleViewContainer(ObstacleView *aObstacleView) {
	obstacleView = aObstacleView;

	ObstacleViewType type = obstacleView->getType();

	std::cout<<MapConstants().getImagePathWithObstacleViewType(type)<<std::endl;
	Gdk::Pixbuf::create_from_file(MapConstants().getImagePathWithObstacleViewType(type));


	image = new Gtk::Image(MapConstants().getImagePathWithObstacleViewType(type));
}

ObstacleViewContainer::ObstacleViewContainer() {}

ObstacleViewContainer::~ObstacleViewContainer() {}


Gtk::Image *ObstacleViewContainer::getImage() {
	if (!isShowing) {
		std::cout<<"entre"<<std::endl;
		image->show();
		image->set_size_request(kObstacleSize, kObstacleSize);
		isShowing = !isShowing;
	}

	return image;
}

ObstacleView *ObstacleViewContainer::getObstacleView() {
	return obstacleView;
}
