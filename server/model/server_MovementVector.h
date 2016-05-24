/*
 * server_movesVector.h
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#ifndef SERVER_MODEL_SERVER_MOVEMENTVECTOR_H_
#define SERVER_MODEL_SERVER_MOVEMENTVECTOR_H_

#include <string>

class MovementVector {
private:
	// Velocity (components x and y), acceleration components (x and y)
	float vx, vy, ax, ay;
public:
	// Constructor
	MovementVector();
	// Destroyer
	virtual ~MovementVector();
	// To string
	std::string toString() const;
	// Get x component of acceleration
	float getAx() const;
	// Set x component of acceleration
	void setAx(float ax);
	// Get y component of acceleration
	float getAy() const;
	// Set y component of acceleration
	void setAy(float ay);
	// Get x component of velocity
	float getVx() const;
	// Set x component of velocity
	void setVx(float vx);
	// Get y component of velocity
	float getVy() const;
	// Set x component of velocity
	void setVy(float vy);
	// Change both directions
	void invertMovement();
};

#endif /* SERVER_MODEL_SERVER_MOVEMENTVECTOR_H_ */
