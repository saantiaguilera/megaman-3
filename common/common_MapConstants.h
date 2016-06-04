/*
 * MapConstants.h
 *
 *  Created on: Jun 4, 2016
 *      Author: santi
 */

#ifndef COMMON_COMMON_MAPCONSTANTS_H_
#define COMMON_COMMON_MAPCONSTANTS_H_

#include <map>

typedef enum {
	//Obstacles

	ObstacleViewTypeLadder = 0,
	ObstacleViewTypeBlock = 1,
	ObstacleViewTypeNeedle = 2,
	ObstacleViewTypePrecipice = 3,
	ObstacleViewTypeBossChamberGate = 4,

	//Spawns

	ObstacleViewTypeMegaman = 5,
	ObstacleViewTypeBumpy = 6,
	ObstacleViewTypeJumpingSnyper = 7,
	ObstacleViewTypeMet = 8,
	ObstacleViewTypeNormalSnyper = 9,

	//Powerups
	ObstacleViewTypeLife = 10,
	ObstacleViewTypeBigEnergyCapsule = 11,
	ObstacleViewTypeSmallEnergyCapsule = 12,
	ObstacleViewTypeBigAmmoPack = 13,
	ObstacleViewTypeSmallAmmoPack = 14
} ObstacleViewType;

#define MAP_NAME "map"
#define ID_NAME "id"
#define MAPNAME_NAME "name"
#define X_NAME "x"
#define Y_NAME "y"
#define SPAWN_TYPE_NAME "type"
#define OBSTACLES_NAME "obstacles"

class MapConstants {
public:
	MapConstants();
	virtual ~MapConstants();

	std::string getImagePathWithObstacleViewType(ObstacleViewType obstacleViewType);

private:
	std::map<ObstacleViewType, std::string> imageMap;

};

#endif /* COMMON_COMMON_MAPCONSTANTS_H_ */
