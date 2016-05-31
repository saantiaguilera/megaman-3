/*
 * server_NewPlayerSerializer.h
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_NEWPLAYERSERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_NEWPLAYERSERIALIZER_H_

#include <string>

#include "server_Serializer.h"

class NewPlayerSerializer: public Serializer {
private:
	std::string playerName;
public:
	// Constructor
	NewPlayerSerializer(std::string playerName);
	// Destroyer
	virtual ~NewPlayerSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	NewPlayerSerializer(const NewPlayerSerializer&);
	// Assignment operator
	NewPlayerSerializer& operator=(const NewPlayerSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_NEWPLAYERSERIALIZER_H_ */
