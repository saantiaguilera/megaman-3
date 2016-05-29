/*
 * server_Player.cpp
 *
 *  Created on: May 22, 2016
 *      Author: mastanca
 */

#include "server_Player.h"

#include "../server_Logger.h"

#define INITIAL_PLAYER_LIVES 3

// Initialize ids value
unsigned int Player::id = 0;

// TODO: WARNING: megaman initial positions hardcoded
Player::Player(const std::string& name) : name(name), lives(INITIAL_PLAYER_LIVES), megaman(this, 0,0){
    Logger::getInstance().log(1, "Player " + name + " added");
	++id;
	// If its the first player then its admin
	// TODO: What happens when restarting game? ids are kept
	if (id == 1)
		admin = true;
}

bool Player::isAdmin() const {
	return admin;
}

unsigned int Player::getLives() const {
	return lives;
}

const std::string& Player::getName() const {
	return name;
}

Player::~Player() {
}

unsigned int Player::getId() const {
	return id;
}

void Player::decreasePlayerLives() {
	if (lives > 0)
		--lives;
}

const Megaman& Player::getMegaman() const {
	return megaman;
}

void Player::increasePlayerLives() {
	++lives;
}
