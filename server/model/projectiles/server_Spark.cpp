/*
 * server_Spark.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#include "server_Spark.h"

Spark::Spark(float32 x, float32 y) : Projectile(SPARKS_DAMAGE, Projectile::SPARK, x, y) {}


Spark::~Spark() {
}

int Spark::getTypeForSerialization() {
	return ObstacleViewTypeSpark;
}

