/*
 * EditorMap.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_EDITOR_EDITORMAP_H_
#define EDITOR_MODELS_EDITOR_EDITORMAP_H_

#include "common_ObstacleView.h"
#include <vector>
#include <string>

class MapView {
public:
	MapView();
	virtual ~MapView();

	//Setters
	void setId(unsigned int id);
	void setName(std::string name);
	void setHeight(unsigned int aHeight);
	void setWidth(unsigned int aWidth);
	void setObstacle(ObstacleView *obstacle);

	//Getters
	std::string getName();
	unsigned int getId();
	unsigned int getWidth();
	unsigned int getHeight();
	ObstacleView * getObstacle(int position);
	std::vector<ObstacleView *> *getObstacles();

private:
	unsigned int id;
	std::string name;
	unsigned int height;
	unsigned int width;

	std::vector<ObstacleView *> *obstacles;
};

#endif /* EDITOR_MODELS_EDITOR_EDITORMAP_H_ */
