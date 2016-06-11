/*
 * ObstacleViewContrainer.h
 *
 *  Created on: Jun 4, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_EDITOR_OBSTACLEVIEWCONTAINER_H_
#define EDITOR_MODELS_EDITOR_OBSTACLEVIEWCONTAINER_H_

#include "../../common/common_MapConstants.h"
#include "../../common/common_ObstacleView.h"
#include "gtkmm.h"

class ObstacleViewContainer {
public:
	ObstacleViewContainer(ObstacleView *aObstacleView);
	ObstacleViewContainer();
	virtual ~ObstacleViewContainer();

	Gtk::Image *getImage();
	ObstacleView *getObstacleView();

private:
	ObstacleView *obstacleView;
	Gtk::Image *image;
	bool isShowing = false;
};

#endif /* EDITOR_MODELS_EDITOR_OBSTACLEVIEWCONTAINER_H_ */
