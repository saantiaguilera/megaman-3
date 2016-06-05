/*
 * server_JsonMapParser.h
 *
 *  Created on: Jun 4, 2016
 *      Author: mastanca
 */

#ifndef SERVER_PARSERS_SERVER_JSONMAPPARSER_H_
#define SERVER_PARSERS_SERVER_JSONMAPPARSER_H_

#include <rapidjson/document.h>

class JsonMapParser {
private:
	rapidjson::Document* document;
public:
	// Constructor
	JsonMapParser(rapidjson::Document* document);
	// Destroyer
	virtual ~JsonMapParser();
	// Parse the json document
	void parseDocument();
private:
	// Copy constructor
	JsonMapParser(const JsonMapParser&);
	// Assignment operator
	JsonMapParser& operator=(const JsonMapParser&);
};

#endif /* SERVER_PARSERS_SERVER_JSONMAPPARSER_H_ */
