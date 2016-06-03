/*
 * EditorObstacle.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "editor_EditorObstacle.h"

#include "../../../common/common_Point.h"

EditorObstacle::EditorObstacle(unsigned int aX, unsigned int aY, unsigned int aHeight, unsigned int aWidth) {
	point.setX(aX);
	point.setY(aY);
	height = aHeight;
	width = aWidth;
}


EditorObstacle::EditorObstacle() {
	// TODO Auto-generated constructor stub

}

EditorObstacle::~EditorObstacle() {
	// TODO Auto-generated destructor stub
}

