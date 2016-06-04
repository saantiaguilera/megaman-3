/*
 * ObstacleView.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: santi
 */

#include "editor_ObstacleView.h"

#include <iostream>

//Constructors
ObstacleView::ObstacleView(EditorObstacle *aEditorObstacle, std::string aPath, Gtk::Image *aImage) {
	editorObstacle = aEditorObstacle;
	path = aPath;
	image = aImage;
}

ObstacleView::ObstacleView() {
	// TODO Auto-generated constructor stub

}

//Destructors
ObstacleView::~ObstacleView() {

}

//Getters
Point ObstacleView::getCenter() {
	float xCenter = editorObstacle->getHeight() / 2.0;
	float yCenter = editorObstacle->getWidth() / 2.0;

	Point center;
	center.setX(xCenter);
	center.setY(yCenter);

	return center;
}

//Setters
void ObstacleView::setPathFile(std::string aPath) {
	std::cout<<"path "<<path<<std::endl;
	path = aPath;
}

void ObstacleView::setImage(Gtk::Image *aImage) {
	image = aImage;
}

//Draw
void ObstacleView::draw() {
	image->set_from_resource(path);
}

void ObstacleView::setEditorObstacle(EditorObstacle *aEditorObstacle) {
	editorObstacle = aEditorObstacle;
}

