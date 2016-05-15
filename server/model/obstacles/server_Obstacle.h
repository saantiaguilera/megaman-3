/*
 * server_Obstacle.h
 *
 *  Created on: May 11, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_OBSTACLES_SERVER_OBSTACLE_H_
#define SERVER_MODEL_OBSTACLES_SERVER_OBSTACLE_H_

class Obstacle {
protected:
	bool passable;
public:
	// Constructor
	Obstacle(bool passable);
	// Destroyer
	virtual ~Obstacle();
	bool isPassable() const;
private:
	// Copy constructor
	Obstacle(const Obstacle&);
	// Assignment operator
	Obstacle& operator=(const Obstacle&);
};

#endif /* SERVER_MODEL_OBSTACLES_SERVER_OBSTACLE_H_ */
