/*
 * MapConstants.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: santi
 */

#include "common_MapConstants.h"

MapConstants::MapConstants() {
	//Obstacle
	imageMap[ObstacleViewTypeLadder] = "./res/drawable/blocks/ladder.png";
	imageMap[ObstacleViewTypeBlock] = "./res/drawable/blocks/block.png";
	imageMap[ObstacleViewTypeNeedle] = "./res/drawable/blocks/spike.png";
	imageMap[ObstacleViewTypePrecipice] = "./res/drawable/blocks/sky.jpg";
	imageMap[ObstacleViewTypeBossChamberGate] = "./res/drawable/blocks/boss_lair.png";

	//Spawns
	imageMap[ObstacleViewTypeMegaman] = "./res/drawable/spawns/megaman/spawn.png";
	imageMap[ObstacleViewTypeBumpy] = "./res/drawable/spawns/bumpy/spawn.png";
	imageMap[ObstacleViewTypeJumpingSnyper] = "./res/drawable/spawns/jumping_sniper/spawn.png";
	imageMap[ObstacleViewTypeMet] = "./res/drawable/spawns/met/spawn.png";
	imageMap[ObstacleViewTypeNormalSnyper] = "./res/drawable/spawns/normal_sniper/spawn.png";

	//Powerups
	imageMap[ObstacleViewTypeLife] = "./res/drawable/powerups/hp/hp.png";
	imageMap[ObstacleViewTypeBigEnergyCapsule] = "./res/drawable/powerups/energy/energy.png";
	imageMap[ObstacleViewTypeSmallEnergyCapsule] = "./res/drawable/powerups/energy/energy.png";
	imageMap[ObstacleViewTypeBigAmmoPack] = "./res/drawable/powerups/ammo/big_ammo.png";
	imageMap[ObstacleViewTypeSmallAmmoPack] = "./res/drawable/powerups/ammo/small_ammo.png";
}

MapConstants::~MapConstants() {}

std::string MapConstants::getImagePathWithObstacleViewType(ObstacleViewType obstacleViewType) {
	return imageMap[obstacleViewType];
}

