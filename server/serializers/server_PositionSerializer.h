/*
 * server_MovementSerializer.h
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_POSITIONSERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_POSITIONSERIALIZER_H_

#include <string>

#include "../../common/common_Serializer.h"

class PositionSerializer : public Serializer {
private:
	// The movements positions, x and y
	float x, y;
protected:
	// Serialize given positions
	std::string serializePosition();
public:
	// Constructor
	PositionSerializer(unsigned int objectId, float x, float y);
	// Destroyer
	virtual ~PositionSerializer();
	// Serialize my object
	virtual void serialize() = 0;
private:
	// Copy constructor
	PositionSerializer(const PositionSerializer&);
	// Assignment operator
	PositionSerializer& operator=(const PositionSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_POSITIONSERIALIZER_H_ */
