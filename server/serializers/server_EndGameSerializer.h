/*
 * server_EndGameSerializer.h
 *
 *  Created on: May 31, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_ENDGAMESERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_ENDGAMESERIALIZER_H_

#include "../../common/common_Serializer.h"

class EndGameSerializer: public Serializer {
public:
	// Constructor
	EndGameSerializer();
	// Destroyer
	virtual ~EndGameSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	EndGameSerializer(const EndGameSerializer&);
	// Assignment operator
	EndGameSerializer& operator=(const EndGameSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_ENDGAMESERIALIZER_H_ */
