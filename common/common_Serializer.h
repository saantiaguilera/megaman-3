/*
 * server_Serializer.h
 *
 *  Created on: May 30, 2016
 *      Author: mastanca
 */

#ifndef COMMON_COMMON_SERIALIZER_H_
#define COMMON_COMMON_SERIALIZER_H_

#include <string>
#include "common_MessageProtocol.h"

class Serializer {
protected:
	// the referenced object id
	unsigned int objectId;
	// The message code
	int messageCode;
	// The serialized string
	std::string serialized;
	// serializer method, pure virtual.
	//@Note: You should call it accordingly in the subclass. The base class wont call it anywhere
	virtual void serialize() = 0;
public:
	// Constructor for messages with no id
	Serializer();
	// Constructor for messages object id
	Serializer(unsigned int objectId);
	// Destroyer
	virtual ~Serializer();
	// Get the serialized string
	std::string getSerialized();
	// Get the related obj id
	unsigned int getObjectId() const;
	int getMessageCode() const;
	int getMessageLength() const;

private:
	// Copy constructor
	Serializer(const Serializer&);
	// Assignment operator
	Serializer& operator=(const Serializer&);
};

#endif /* COMMON_COMMON_SERIALIZER_H_ */