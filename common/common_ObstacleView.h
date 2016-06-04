/*
 * EditorObstacle.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_OBSTACLES_EDITOR_EDITOROBSTACLE_H_
#define EDITOR_MODELS_OBSTACLES_EDITOR_EDITOROBSTACLE_H_

#include "common_Point.h"

class ObstacleView {
public:
	ObstacleView(unsigned int aX, unsigned int aY);
	ObstacleView();
	virtual ~ObstacleView();

	Point getPoint();

protected:
		Point point;
};

//Tiene que haber bloques puas escaleras y presipicios

#endif /* EDITOR_MODELS_OBSTACLES_EDITOR_EDITOROBSTACLE_H_ */
