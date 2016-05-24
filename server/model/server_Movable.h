/*
 * IMovable.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_SERVER_MOVABLE_H_
#define SERVER_MODEL_SERVER_MOVABLE_H_

#include "../../common/common_Point.h"
#include "server_MovementVector.h"

class Movable {
protected:
	// Actual position
	Point position;
	// Holder of the movement
	MovementVector movementVector;
public:
	// Constructor
	Movable();
	// Destroyer
	virtual ~Movable();
	// Move according to movements vector values
	void move();
private:
	// Copy constructor
	Movable(const Movable&);
	// Assignment operator
	Movable& operator=(const Movable&);
};

#endif /* SERVER_MODEL_SERVER_MOVABLE_H_ */
