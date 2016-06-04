/*
 * server_StartGameSerializer.h
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_STARTGAMESERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_STARTGAMESERIALIZER_H_

#include "../../common/server_Serializer.h"

class StartGameSerializer: public Serializer {
public:
	// Constructor
	StartGameSerializer();
	// Destroyer
	virtual ~StartGameSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	StartGameSerializer(const StartGameSerializer&);
	// Assignment operator
	StartGameSerializer& operator=(const StartGameSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_STARTGAMESERIALIZER_H_ */
