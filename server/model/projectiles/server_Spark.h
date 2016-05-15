/*
 * server_Spark.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_PROJECTILES_SERVER_SPARK_H_
#define SERVER_MODEL_PROJECTILES_SERVER_SPARK_H_

#include "server_Projectile.h"

#define SPARKS_DAMAGE 4

class Spark: public Projectile {
public:
	// Constructor
	Spark() : Projectile(SPARKS_DAMAGE, Projectile::SPARK) {}
	// Destroyer
	virtual ~Spark();
private:
	// Copy constructor
	Spark(const Spark&);
	// Assignment operator
	Spark& operator=(const Spark&);
};

#endif /* SERVER_MODEL_PROJECTILES_SERVER_SPARK_H_ */
