/*
 * server_HpChangeSerializer.h
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_HPCHANGESERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_HPCHANGESERIALIZER_H_

#include "../../common/common_Serializer.h"

#include "../../server/model/characters/server_Character.h"

class HpChangeSerializer: public Serializer {
private:
	unsigned int newHp;
	Character *character;
public:
	// Constructor
	HpChangeSerializer(unsigned int newHp, Character* character);
	// Destroyer
	virtual ~HpChangeSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	HpChangeSerializer(const HpChangeSerializer&);
	// Assignment operator
	HpChangeSerializer& operator=(const HpChangeSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_HPCHANGESERIALIZER_H_ */
