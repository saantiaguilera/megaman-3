/*
 * MapWindowValidator.cpp
 *
 *  Created on: Jul 2, 2016
 *      Author: santi
 */

#include "editor_MapWindowValidator.h"

#include <iostream>

MapWindowValidator::MapWindowValidator() {
	isMegamanSet = true;
	isBossSet = true;
	isBosschamberSet = true;
}

MapWindowValidator::~MapWindowValidator() {
	// TODO Auto-generated destructor stub
}

void MapWindowValidator::setMegaman() {
	isMegamanSet = true;
}

void MapWindowValidator::setBoss() {
	isBossSet = true;
}

void MapWindowValidator::setBosschamber() {
	std::cout << "set boss chamber" << std::boolalpha << isBosschamberSet << std::endl;
	isBosschamberSet = true;
	std::cout << "did set boss chamber" << std::boolalpha << isBosschamberSet << std::endl;
}

void MapWindowValidator::removeMegaman() {
	isMegamanSet = false;
}

void MapWindowValidator::removeBoss() {
	isBossSet = false;
}

void MapWindowValidator::removeBosschamber() {
	std::cout << "remove boss chamber" << std::boolalpha << isBosschamberSet << std::endl;
	isBosschamberSet = false;
	std::cout << "did remove boss chamber" << std::boolalpha << isBosschamberSet << std::endl;
}

bool MapWindowValidator::didSetMegaman() {
	return isMegamanSet;
}

bool MapWindowValidator::didSetBoss() {
	return isBossSet;
}
bool MapWindowValidator::didSetBosschamber() {
	return isBosschamberSet;
}
