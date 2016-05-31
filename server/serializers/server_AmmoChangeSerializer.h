/*
 * server_AmmoChangeSerializer.h
 *
 *  Created on: May 31, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_AMMOCHANGESERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_AMMOCHANGESERIALIZER_H_

#include "server_Serializer.h"

class AmmoChangeSerializer: public Serializer {
private:
	unsigned int newAmmo;
public:
	// Constructor
	AmmoChangeSerializer(unsigned int newAmmo, unsigned int objectId);
	// Destroyer
	virtual ~AmmoChangeSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	AmmoChangeSerializer(const AmmoChangeSerializer&);
	// Assignment operator
	AmmoChangeSerializer& operator=(const AmmoChangeSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_AMMOCHANGESERIALIZER_H_ */
