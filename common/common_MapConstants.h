/*
ss * MapConstants.h
 *
 *  Created on: Jun 4, 2016
 *      Author: santi
 */

#ifndef COMMON_COMMON_MAPCONSTANTS_H_
#define COMMON_COMMON_MAPCONSTANTS_H_

#define TERRAIN_TILE_SIZE 70
#define METERS_TO_PIXELS_RATIO 0.02f

#include <map>

typedef enum {
	//Obstacles

	ObstacleViewTypeLadder = 0,
	ObstacleViewTypeBlock = 1,
	ObstacleViewTypeBlock1 = 2,
	ObstacleViewTypeBlock2 = 3,
	ObstacleViewTypeBlock3 = 4,

	ObstacleViewTypeNeedle = 5,
	ObstacleViewTypePrecipice = 6,
	ObstacleViewTypeBossChamberGate = 7,

	//Spawns

	ObstacleViewTypeMegaman = 8,
	ObstacleViewTypeBumpy = 9,
	ObstacleViewTypeJumpingSnyper = 10,
	ObstacleViewTypeMet = 11,
	ObstacleViewTypeNormalSnyper = 12,

	//Powerups
	ObstacleViewTypeLife = 13,
	ObstacleViewTypeBigEnergyCapsule = 14,
	ObstacleViewTypeSmallEnergyCapsule = 15,
	ObstacleViewTypeBigAmmoPack = 16,
	ObstacleViewTypeSmallAmmoPack = 17,

	// Bosses
	ObstacleViewTypeBombman = 18,
	ObstacleViewTypeFireman = 19,
	ObstacleViewTypeMagnetman = 20,
	ObstacleViewTypeRingman = 21,
	ObstacleViewTypeSparkman = 22,

	// Projectiles
	ObstacleViewTypeBomb = 23,
	ObstacleViewTypeFire = 24,
	ObstacleViewTypeMagnet = 25,
	ObstacleViewTypeRing = 26,
	ObstacleViewTypeSpark = 27,
	ObstacleViewTypePlasma = 28
} ObstacleViewType;

typedef enum {
	Weapon1 = ObstacleViewTypePlasma,
	Weapon2 = ObstacleViewTypeSpark,
	Weapon3 = ObstacleViewTypeRing,
	Weapon4 = ObstacleViewTypeMagnet,
	Weapon5 = ObstacleViewTypeFire,
	Weapon6 = ObstacleViewTypeBomb
} WeaponType;

#define MAP_NAME "map"
#define ID_NAME "id"
#define MAPNAME_NAME "name"
#define MAPHEIGHT_NAME "height"
#define MAPWIDTH_NAME "width"
#define MAPFILENAME_NAME "filename"
#define MAPBACKGROUNDIMAGE_NAME "background_image"

#define MAP_DEFAULT_BACKGROUND_IMAGE_PATH "res/drawable/background/background1.png"

#define MAPOBSTACLES_NAME "obstacles"

#define X_NAME "x"
#define Y_NAME "y"
#define TYPE_NAME "type"

class MapConstants {
public:
	MapConstants();
	virtual ~MapConstants();

	std::string getImagePathWithObstacleViewType(ObstacleViewType obstacleViewType);

private:
	std::map<ObstacleViewType, std::string> imageMap;
};

#endif /* COMMON_COMMON_MAPCONSTANTS_H_ */
