/*
 * server_Player.cpp
 *
 *  Created on: May 22, 2016
 *      Author: mastanca
 */

#include "server_Player.h"

#include "../serializers/server_ObjectCreationSerializer.h"
#include "../server_Logger.h"
#include "server_Engine.h"
#include "server_EventContext.h"

// Initialize ids value
unsigned int Player::id = 0;

// TODO: WARNING: megaman initial positions hardcoded
Player::Player(const std::string& name, unsigned int initialLives) : name(name), lives(initialLives){
    Logger::getInstance().log(1, "Player " + name + " added");
	++id;
	// If its the first player then its admin
	// TODO: What happens when restarting game? ids are kept
	if (id == 1)
		admin = true;
	megaman = new Megaman(this, 0, 0);
	ObjectCreationSerializer* objectCreationSerializer = new ObjectCreationSerializer(megaman->getId(), megaman->getPositionX(), megaman->getPositionY());
	Engine::getInstance().getContext()->dispatchEvent(objectCreationSerializer);
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
	if (lives == 0)
		Engine::getInstance().markObjectForRemoval(megaman);
}

Megaman* Player::getMegaman() const {
	return megaman;
}

void Player::increasePlayerLives() {
	++lives;
}
