/*
 * EditorObstacle.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "common_ObstacleView.h"

//Constructors
ObstacleView::ObstacleView(unsigned int aX, unsigned int aY, unsigned int aHeight, unsigned int aWidth) {
	point.setX(aX);
	point.setY(aY);
	height = aHeight;
	width = aWidth;
}


ObstacleView::ObstacleView(){
}

//Destructors
ObstacleView::~ObstacleView() {
}

//Getters
unsigned int ObstacleView::getHeight() {
	return height;
}

unsigned int ObstacleView::getWidth() {
	return width;
}
Point ObstacleView::getPoint() {
	return point;
}
