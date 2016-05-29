/*
 * EditorObstacle.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_OBSTACLES_EDITOR_EDITOROBSTACLE_H_
#define EDITOR_MODELS_OBSTACLES_EDITOR_EDITOROBSTACLE_H_

#include "../../../common/common_Point.h"

class EditorObstacle {
public:
	EditorObstacle(Point aPoint, unsigned int aHeight, unsigned int aWidth);
	EditorObstacle();
	virtual ~EditorObstacle();

protected:
		Point point;
		unsigned int height;
		unsigned int width;
};

//Tiene que haber bloques puas escaleras y presipicios

#endif /* EDITOR_MODELS_OBSTACLES_EDITOR_EDITOROBSTACLE_H_ */
