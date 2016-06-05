/*
 * server_MovementSerializer.h
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_MOVEMENTSERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_MOVEMENTSERIALIZER_H_

#include "server_PositionSerializer.h"

class MovementSerializer: public PositionSerializer {
public:
	// Constructor
	MovementSerializer(unsigned int objectId, float x, float y);
	// Destroyer
	virtual ~MovementSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	MovementSerializer(const MovementSerializer&);
	// Assignment operator
	MovementSerializer& operator=(const MovementSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_MOVEMENTSERIALIZER_H_ */
