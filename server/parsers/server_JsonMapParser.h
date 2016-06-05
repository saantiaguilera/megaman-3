/*
 * server_JsonMapParser.h
 *
 *  Created on: Jun 4, 2016
 *      Author: mastanca
 */

#ifndef SERVER_PARSERS_SERVER_JSONMAPPARSER_H_
#define SERVER_PARSERS_SERVER_JSONMAPPARSER_H_

#include <string>


class JsonMapParser {
public:
	// Constructor
	JsonMapParser();
	// Destroyer
	virtual ~JsonMapParser();
	// Parse the json document
	void parseDocument(const std::string& name);
private:
	// Copy constructor
	JsonMapParser(const JsonMapParser&);
	// Assignment operator
	JsonMapParser& operator=(const JsonMapParser&);
};

#endif /* SERVER_PARSERS_SERVER_JSONMAPPARSER_H_ */
