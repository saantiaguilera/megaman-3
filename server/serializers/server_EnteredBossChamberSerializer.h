/*
 * server_EnteredBossChamberSerializer.h
 *
 *  Created on: Jun 6, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_ENTEREDBOSSCHAMBERSERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_ENTEREDBOSSCHAMBERSERIALIZER_H_

#include "../../common/common_Serializer.h"

class EnteredBossChamberSerializer: public Serializer {
public:
	// Constructor
	EnteredBossChamberSerializer();
	// Destroyer
	virtual ~EnteredBossChamberSerializer();
	// Serialize object
	virtual void serialize();
private:
	// Copy constructor
	EnteredBossChamberSerializer(const EnteredBossChamberSerializer&);
	// Assignment operator
	EnteredBossChamberSerializer& operator=(const EnteredBossChamberSerializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_ENTEREDBOSSCHAMBERSERIALIZER_H_ */
