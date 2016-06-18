/*
 * server_ConnectedPlayerSerializer.h
 *
 *  Created on: Jun 17, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_CONNECTEDPLAYERSERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_CONNECTEDPLAYERSERIALIZER_H_

#include "../../common/common_Serializer.h"

class Megaman;

class ConnectedPlayerSerializer: public Serializer {
private:
	Megaman* megaman;
public:
	// Constructor
	ConnectedPlayerSerializer(Megaman* megaman);
	// Destroyer
	virtual ~ConnectedPlayerSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	ConnectedPlayerSerializer(const ConnectedPlayerSerializer&);
	// Assignment operator
	ConnectedPlayerSerializer& operator=(const ConnectedPlayerSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_CONNECTEDPLAYERSERIALIZER_H_ */
