/*
 * server_Serializer.h
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERIALIZERS_SERVER_SERIALIZER_H_
#define SERVER_SERIALIZERS_SERVER_SERIALIZER_H_

#include <string>
#include "../../common/common_MessageProtocol.h"

class Serializer {
protected:
	// the referenced object id
	unsigned int objectId;
	// The serialized string
	std::string serialized;
public:
	// Constructor for messages with no id
	Serializer();
	// Constructor for messages object id
	Serializer(unsigned int objectId);
	// Destroyer
	virtual ~Serializer();
	// Get the serialized string
	const std::string& getSerialized() const;
	// serializer method, pure virtual
	virtual void seralize() = 0;
	// Serialize id
	std::string serializeObjectId();
private:
	// Copy constructor
	Serializer(const Serializer&);
	// Assignment operator
	Serializer& operator=(const Serializer&);
};

#endif /* SERVER_SERIALIZERS_SERVER_SERIALIZER_H_ */
