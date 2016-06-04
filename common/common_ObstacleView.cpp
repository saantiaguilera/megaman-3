/*
 * EditorObstacle.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "common_ObstacleView.h"

//Constructors
ObstacleView::ObstacleView(unsigned int aX, unsigned int aY) {
	point.setX(aX);
	point.setY(aY);

}


ObstacleView::ObstacleView(){
}

//Destructors
ObstacleView::~ObstacleView() {
}
Point ObstacleView::getPoint() {
	return point;
}
