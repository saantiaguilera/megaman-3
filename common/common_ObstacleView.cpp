/*
 * EditorObstacle.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "common_ObstacleView.h"

//Constructors
ObstacleView::ObstacleView(unsigned int aX, unsigned int aY, ObstacleViewType aType) {
	point.setX(aX);
	point.setY(aY);
	type = aType;
}


ObstacleView::ObstacleView(){
}

//Destructors
ObstacleView::~ObstacleView() {
}

Point ObstacleView::getPoint() {
	return point;
}

ObstacleViewType ObstacleView::getType() {
	return type;
}
