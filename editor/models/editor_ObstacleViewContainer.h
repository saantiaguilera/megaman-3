/*
 * ObstacleViewContrainer.h
 *
 *  Created on: Jun 4, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_EDITOR_OBSTACLEVIEWCONTAINER_H_
#define EDITOR_MODELS_EDITOR_OBSTACLEVIEWCONTAINER_H_

#include "../../common/common_MapConstants.h"
#include "gtkmm.h"

#define kObstacleSize 100

class ObstacleViewContainer {
public:
	ObstacleViewContainer(ObstacleViewType aType);
	ObstacleViewContainer();
	virtual ~ObstacleViewContainer();

	Gtk::Image *getImage();

private:
	ObstacleViewType type;
	Gtk::Image *image;
};

#endif /* EDITOR_MODELS_EDITOR_OBSTACLEVIEWCONTAINER_H_ */
