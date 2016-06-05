/*
 * EditorObstacle.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_OBSTACLES_EDITOR_EDITOROBSTACLE_H_
#define EDITOR_MODELS_OBSTACLES_EDITOR_EDITOROBSTACLE_H_

#include "common_Point.h"
#include "common_MapConstants.h"

class ObstacleView {
public:
	ObstacleView(unsigned int aX, unsigned int aY, ObstacleViewType aType);
	ObstacleView();
	virtual ~ObstacleView();

	Point getPoint();
	ObstacleViewType getType();

	//Setters
	void setPosition(unsigned int aX, unsigned int aY);
	void setType(ObstacleViewType aType);

protected:
		Point point;
		ObstacleViewType type;
};

//Tiene que haber bloques puas escaleras y presipicios

#endif /* EDITOR_MODELS_OBSTACLES_EDITOR_EDITOROBSTACLE_H_ */
