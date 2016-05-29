/*
 * server_ConfigParser.h
 *
 *  Created on: May 29, 2016
 *      Author: mastanca
 */

#ifndef SERVER_PARSERS_SERVER_CONFIGPARSER_H_
#define SERVER_PARSERS_SERVER_CONFIGPARSER_H_

#include <string>
#include "rapidjson/document.h"

class ConfigParser {
private:
	unsigned int playerInitialLives, gameVelocity, humanoidsVelocity, mobsVelocity;
	FILE* pFile;
	rapidjson::Document document;
public:
	// Constructor
	ConfigParser(const std::string& configFilename);
	// Destroyer
	virtual ~ConfigParser();
	// Get game velocity
	unsigned int getGameVelocity() const;
	// Get humanoids velocity
	unsigned int getHumanoidsVelocity() const;
	// Get mobs velocity
	unsigned int getMobsVelocity() const;
	// Get player initial lives
	unsigned int getPlayerInitialLives() const;
	// Parse the document
	void parseConfigDoc();

private:
	// Copy constructor
	ConfigParser(const ConfigParser&);
	// Assignment operator
	ConfigParser& operator=(const ConfigParser&);
};

#endif /* SERVER_PARSERS_SERVER_CONFIGPARSER_H_ */
