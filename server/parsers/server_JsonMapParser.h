/*
 * server_JsonMapParser.h
 *
 *  Created on: Jun 4, 2016
 *      Author: mastanca
 */

#ifndef SERVER_PARSERS_SERVER_JSONMAPPARSER_H_
#define SERVER_PARSERS_SERVER_JSONMAPPARSER_H_

class JsonMapParser {
public:
	// Constructor
	JsonMapParser(int mapNumber);
	// Destroyer
	virtual ~JsonMapParser();
private:
	// Copy constructor
	JsonMapParser(const JsonMapParser&);
	// Assignment operator
	JsonMapParser& operator=(const JsonMapParser&);
};

#endif /* SERVER_PARSERS_SERVER_JSONMAPPARSER_H_ */
