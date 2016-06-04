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

	ObstacleViewTypeLadder,
	ObstacleViewTypeBlock,
	ObstacleViewTypeNeedle,
	ObstacleViewTypePrecipice,
	ObstacleViewTypeBossChamberGate,

	//Spawns

	ObstacleViewTypeMegaman,
	ObstacleViewTypeBumpy,
	ObstacleViewTypeJumpingSnyper,
	ObstacleViewTypeMet,
	ObstacleViewTypeNormalSnyper,

	//Powerups
	ObstacleViewTypeLife,
	ObstacleViewTypeBigEnergyCapsule,
	ObstacleViewTypeSmallEnergyCapsule,
	ObstacleViewTypeBigAmmoPack,
	ObstacleViewTypeSmallAmmoPack

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
