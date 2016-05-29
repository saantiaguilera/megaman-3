/*
 * server_ConfigParser.cpp
 *
 *  Created on: May 29, 2016
 *      Author: mastanca
 */

#include "server_ConfigParser.h"

#include <rapidjson/filereadstream.h>
#include <cstdio>
#include <iostream>

#include "../server_Logger.h"

#define DEFAULT_PLAYER_LIVES 3
#define DEFUALT_GAME_VELOCITY 1/20
#define DEFAULT_HUMANOIDS_VELOCITY 1
#define DEFAULT_MOBS_VELOCITY 1

ConfigParser::ConfigParser(const std::string& configFilename) :
		playerInitialLives(DEFAULT_PLAYER_LIVES), gameVelocity(
				DEFUALT_GAME_VELOCITY), humanoidsVelocity(
				DEFAULT_HUMANOIDS_VELOCITY), mobsVelocity(DEFAULT_MOBS_VELOCITY) {
	std::string filename = "./json/" + configFilename;

	pFile = fopen(filename.c_str(), "rb");
	if(pFile == NULL)
		Logger::getInstance().log(3, "Error opening config file");
	char buffer[65536];
	rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
	document.ParseStream<rapidjson::FileReadStream>(is);
	if(document.HasParseError())
		Logger::getInstance().log(3, "Error parsing JSON file");
}

unsigned int ConfigParser::getGameVelocity() const {
	return gameVelocity;
}

unsigned int ConfigParser::getHumanoidsVelocity() const {
	return humanoidsVelocity;
}

unsigned int ConfigParser::getMobsVelocity() const {
	return mobsVelocity;
}

unsigned int ConfigParser::getPlayerInitialLives() const {
	return playerInitialLives;
}

ConfigParser::~ConfigParser() {
	fclose(pFile);
}

void ConfigParser::parseConfigDoc() {
	// Parsers are ugly, by definition
	if(document.HasMember("config")){
		if(document["config"].HasMember("player_initial_lives")){
			playerInitialLives = document["config"]["player_initial_lives"].GetUint();
		} else {
			Logger::getInstance().log(1, "Using default value for player lives");
		}
		if(document["config"].HasMember("game_velocity")){
			gameVelocity = document["config"]["game_velocity"].GetUint();
		} else {
			Logger::getInstance().log(1, "Using default value for game velocity");
		}
		if(document["config"].HasMember("characters_velocity")){
			if(document["config"]["characters_velocity"].HasMember("humanoids")){
				humanoidsVelocity = document["config"]["characters_velocity"]["humanoids"].GetUint();
			} else {
				Logger::getInstance().log(1, "Using default value for humanoids velocities");
			}
			if(document["config"]["characters_velocity"].HasMember("mobs")){
				mobsVelocity = document["config"]["characters_velocity"]["mobs"].GetUint();
			} else {
				Logger::getInstance().log(1, "Using default value for mobs velocities");
			}
		} else {
			Logger::getInstance().log(1, "Using default value for velocities");
		}
	} else {
		Logger::getInstance().log(2, "Using default values for configs");
	}
}
// Examples
//    std::cout << document["map"].GetInt() << std::endl;
//    const rapidjson::Value& a = document["response"];
//    for (rapidjson::Value::ConstValueIterator itr = a.Begin(); itr != a.End(); ++itr)
//        std::cout << itr->GetObject()["id"].GetInt() << std::endl;
