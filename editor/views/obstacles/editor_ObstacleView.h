/*
 * ObstacleView.h
 *
 *  Created on: Jun 2, 2016
 *      Author: santi
 */

#ifndef EDITOR_VIEWS_OBSTACLES_EDITOR_OBSTACLEVIEW_H_
#define EDITOR_VIEWS_OBSTACLES_EDITOR_OBSTACLEVIEW_H_

#include <gtkmm.h>
#include "../../../common/common_Point.h"
#include <string>
#include "../../models/obstacles/editor_EditorObstacle.h"

class ObstacleView {
public:
	//Constructors
	ObstacleView(EditorObstacle *aEditorObstacle, std::string path, Gtk::Image *aImage);
	ObstacleView();

	//Destructors
	virtual ~ObstacleView();

	//Getters
	Point getCenter();

	//Setters
	void setEditorObstacle(EditorObstacle *aEditorObstacle);
	void setPathFile(std::string path);
	void setImage(Gtk::Image *aImage);
	//Drawing
	void draw();


private :
	Gtk::Image *image;
	EditorObstacle *editorObstacle;
    std::string path;

};

#endif /* EDITOR_VIEWS_OBSTACLES_EDITOR_OBSTACLEVIEW_H_ */
