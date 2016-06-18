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
private:

	bool dispatchAll = true;

	unsigned int dispatchClientID = 0;

protected:
	// the referenced object id
	unsigned int objectId;
	// The message code
	int messageCode;
	// The objects type
	int objectType;
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
	// Constructor for messages object id and tye
	Serializer(unsigned int objectId, int objectType);
	// Destroyer
	virtual ~Serializer();
	// Get the serialized string
	std::string getSerialized();
	// Get the related obj id
	unsigned int getObjectId() const;
	// Return the message's code
	int getMessageCode() const;
	// Return the serialized message length
	int getMessageLength() const;
	// Get the object types
	int getObjectType();
	// Set event to be dispatched to all clients
	void setDispatchAll();
	// Set event to be dispatched to a perticular clientID
	void setDispatchClient(unsigned int clientID);
	// Get if event is dispatched to all clients
	bool getDispatchAll();
	// Get the clientID that has to be dispatched the event to
	unsigned int getDispatchClientID();

private:
	// Copy constructor
	Serializer(const Serializer&);
	// Assignment operator
	Serializer& operator=(const Serializer&);
};



#endif /* COMMON_COMMON_SERIALIZER_H_ */
