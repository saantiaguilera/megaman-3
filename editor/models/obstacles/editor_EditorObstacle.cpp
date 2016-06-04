/*
 * EditorObstacle.cpp
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#include "editor_EditorObstacle.h"

#include "../../../common/common_Point.h"

//Constructors
EditorObstacle::EditorObstacle(unsigned int aX, unsigned int aY, unsigned int aHeight, unsigned int aWidth) {
	point.setX(aX);
	point.setY(aY);
	height = aHeight;
	width = aWidth;
}


EditorObstacle::EditorObstacle(){
}

//Destructors
EditorObstacle::~EditorObstacle() {
}

//Getters
unsigned int EditorObstacle::getHeight() {
	return height;
}

unsigned int EditorObstacle::getWidth() {
	return width;
}
Point EditorObstacle::getPoint() {
	return point;
}
