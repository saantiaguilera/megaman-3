/*
 * IMovable.h
 *
 *  Created on: May 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_IMOVABLE_H_
#define SERVER_MODEL_IMOVABLE_H_

#include "../../common/common_Point.h"

class IMovable {
private:
	// my current position
	Point myPoint;
public:
	// Constructor
	IMovable() {}
	// Destroyer
	virtual ~IMovable();
	// Move right (x + 1)
	void moveRight();
	// Move right (y + 1)
	void moveUp();
	// Move right (x - 1)
	void moveLeft();
	// Move right (y - 1)
	void moveDown();
	const Point& getMyPoint() const;

private:
	// Copy constructor
	IMovable(const IMovable&);
	// Assignment operator
	IMovable& operator=(const IMovable&);
};

#endif /* SERVER_MODEL_IMOVABLE_H_ */
