/*
 * MapConstants.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: santi
 */

#include "common_MapConstants.h"

MapConstants::MapConstants() {
	//Obstacle
	imageMap[ObstacleViewTypeLadder] = "hola";
	imageMap[ObstacleViewTypeBlock] = "hola";
	imageMap[ObstacleViewTypeNeedle] = "hola";
	imageMap[ObstacleViewTypePrecipice] = "hola";
	imageMap[ObstacleViewTypeBossChamberGate] = "hola";

	//Spawns
	imageMap[ObstacleViewTypeMegaman] = "hola";
	imageMap[ObstacleViewTypeBumpy] = "hola";
	imageMap[ObstacleViewTypeJumpingSnyper] = "hola";
	imageMap[ObstacleViewTypeMet] = "hola";
	imageMap[ObstacleViewTypeNormalSnyper] = "hola";

	//Powerups
	imageMap[ObstacleViewTypeLife] = "hola";
	imageMap[ObstacleViewTypeBigEnergyCapsule] = "hola";
	imageMap[ObstacleViewTypeSmallEnergyCapsule] = "hola";
	imageMap[ObstacleViewTypeBigAmmoPack] = "hola";
	imageMap[ObstacleViewTypeSmallAmmoPack] = "hola";
}

MapConstants::~MapConstants() {
	// TODO Auto-generated destructor stub
}

std::string MapConstants::getImagePathWithObstacleViewType(ObstacleViewType obstacleViewType) {
	return imageMap[obstacleViewType];
}

