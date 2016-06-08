/*
 * server_ConfigParser.cpp
 *
 *  Created on: May 29, 2016
 *      Author: mastanca
 */

#include "server_ConfigParser.h"

#include "../../common/rapidjson/filereadstream.h"
#include <cstdio>
#include <iostream>

#include "../server_Logger.h"

#define DEFAULT_PLAYER_LIVES 3
#define DEFAULT_GAME_TIMESTEP 0.05
#define DEFAULT_HUMANOIDS_VELOCITY 1
#define DEFAULT_MOBS_VELOCITY 1
#define DEFAULT_GRAVITY -9.8
#define DEFAULT_VELOCITY_ITERATIONS 8
#define DEFAULT_POSITION_ITERATIONS 3

ConfigParser::ConfigParser(const std::string& configFilename) :
		playerInitialLives(DEFAULT_PLAYER_LIVES), humanoidsVelocity(
		DEFAULT_HUMANOIDS_VELOCITY), mobsVelocity(DEFAULT_MOBS_VELOCITY), velocityIterations(
		DEFAULT_VELOCITY_ITERATIONS), positionIterations(
		DEFAULT_POSITION_ITERATIONS), timestep(DEFAULT_GAME_TIMESTEP), gravity(
		DEFAULT_GRAVITY) {
	std::string filename = "./json/" + configFilename;

	pFile = fopen(filename.c_str(), "rb");
	if (pFile == NULL)
		Logger::getInstance().log(3, "Error opening config file");
	char buffer[65536];
	rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
	document.ParseStream<rapidjson::FileReadStream>(is);
	if (document.HasParseError())
		Logger::getInstance().log(3, "Error parsing JSON file");
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

float ConfigParser::getGravity() const {
	return gravity;
}

unsigned int ConfigParser::getPositionIterations() const {
	return positionIterations;
}

float ConfigParser::getTimestep() const {
	return timestep;
}

unsigned int ConfigParser::getVelocityIterations() const {
	return velocityIterations;
}

void ConfigParser::parseConfigDoc() {
	// Parsers are ugly, by definition
	if (document.HasMember("config")) {
		if (document["config"].HasMember("player_initial_lives")) {
			playerInitialLives =
					document["config"]["player_initial_lives"].GetUint();
		} else {
			Logger::getInstance().log(1,
					"Using default value for player lives");
		}
		if (document["config"].HasMember("characters_velocity")) {
			if (document["config"]["characters_velocity"].HasMember(
					"humanoids")) {
				humanoidsVelocity =
						document["config"]["characters_velocity"]["humanoids"].GetUint();
			} else {
				Logger::getInstance().log(1,
						"Using default value for humanoids velocities");
			}
			if (document["config"]["characters_velocity"].HasMember("mobs")) {
				mobsVelocity =
						document["config"]["characters_velocity"]["mobs"].GetUint();
			} else {
				Logger::getInstance().log(1,
						"Using default value for mobs velocities");
			}
		} else {
			Logger::getInstance().log(1, "Using default value for velocities");
		}
		if (document["config"].HasMember("game")) {
			if (document["config"]["game"].HasMember("gravity")) {
				gravity = document["config"]["game"]["gravity"].GetFloat();
			} else {
				Logger::getInstance().log(1, "Using default value for gravity");
			}
			if (document["config"]["game"].HasMember("timestep")) {
				timestep = document["config"]["game"]["timestep"].GetFloat();
			} else {
				Logger::getInstance().log(1,
						"Using default value for mobs velocities");
			}
			if (document["config"]["game"].HasMember("velocity_iterarions")) {
				velocityIterations =
						document["config"]["game"]["velocity_iterarions"].GetUint();
			} else {
				Logger::getInstance().log(1,
						"Using default value for mobs velocities");
			}
			if (document["config"]["game"].HasMember("position_iterarions")) {
				positionIterations =
						document["config"]["game"]["position_iterarions"].GetUint();
			} else {
				Logger::getInstance().log(1,
						"Using default value for mobs velocities");
			}
		} else {
			Logger::getInstance().log(1,
					"Using default value for game configs");
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
