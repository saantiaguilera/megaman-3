/*
 * EditorMap.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_EDITOR_EDITORMAP_H_
#define EDITOR_MODELS_EDITOR_EDITORMAP_H_

#include "obstacles/editor_EditorObstacle.h"
#include <vector>
#include <string>

class EditorMap {
public:
	EditorMap();
	virtual ~EditorMap();

	void setId(unsigned int id);
	void setName(std::string name);

	//Setters
	void setSpawn(EditorObstacle *aSpawn);
	void setNeedle(EditorObstacle *aNeedle);
	void setPrecipice(EditorObstacle *aPrecipice);
	void setBlock(EditorObstacle *aBlock);

	//Getters
	std::string getName();

private:
	unsigned int id;
	std::string name;

	std::vector<EditorObstacle *> *spawns;
	std::vector<EditorObstacle *> *needles;
	std::vector<EditorObstacle *> *precipices;
	std::vector<EditorObstacle *> *blocks;
};

#endif /* EDITOR_MODELS_EDITOR_EDITORMAP_H_ */

/*{
  "map": {
    "id": 1,
    "name": "Bombman",
    "spawns": [
      {
        "x": 15,
        "y": 0,
        "type": "Met"
      },
      {
        "x": 23,
        "y": 5,
        "type": "CommonSniper"
      }
    ],
    "needles": [
      {
        "x": 10,
        "y": 10
      }
    ],
    "precipices": [
      {
        "x": 30,
        "y": 0
      }
    ],
    "blocks": [
      {
        "x": 2,
        "y": 0
      },
      {
        "x": 2,
        "y": 5
      },
      {
        "x": 10,
        "y": 0
      }
    ]
  }
}*/
