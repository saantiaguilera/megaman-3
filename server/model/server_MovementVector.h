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
	unsigned int x,y;
	float velocity, acceleration;
public:
	MovementVector();
	virtual ~MovementVector();
	float getAcceleration() const;
	void setAcceleration(float acceleration);
	float getVelocity() const;
	void setVelocity(float velocity);
	unsigned int getX() const;
	void setX(unsigned int x);
	unsigned int getY() const;
	void setY(unsigned int y);
	// To string
	std::string toString() const;
};

#endif /* SERVER_MODEL_SERVER_MOVEMENTVECTOR_H_ */
