/*
 * common_Point.h
 *
 *  Created on: May 14, 2016
 *      Author: mastanca
 */

#ifndef COMMON_COMMON_POINT_H_
#define COMMON_COMMON_POINT_H_

class Point {
private:
	// Actual positions
	unsigned int x, y;
public:
	// Cosntructor
	Point();
	// Destroyer
	virtual ~Point();
	// return x position
	unsigned int getX() const;
	// set x position
	void setX(unsigned int x);
	// get y position
	unsigned int getY() const;
	// set y position
	void setY(unsigned int y);
};

#endif /* COMMON_COMMON_POINT_H_ */
