/*
 * server_Player.cpp
 *
 *  Created on: May 22, 2016
 *      Author: mastanca
 */

#include "server_Player.h"

#include "../serializers/server_ConnectedPlayerSerializer.h"
#include "../serializers/server_LifeChangeSerializer.h"
#include "../server_Logger.h"
#include "server_Engine.h"
#include "server_EventContext.h"

// Note: Due to implementation of connections, the second player connected is
// assigned as admin, there is always one proxy waiting for connection
#define ADMIN_ID 1

Player::Player(unsigned int id, const std::string& name,
		unsigned int initialLives) :
		id(id), name(name), lives(initialLives) {
	Logger::getInstance().log(1, "Player " + name + " added");
	if (id == ADMIN_ID)
		admin = true;
	megaman = NULL;
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
	if (lives > 0){
		--lives;
		LifeChangeSerializer* lifeChangeSerializer = new LifeChangeSerializer(getLives());
		lifeChangeSerializer->setDispatchClient(getId());
		Engine::getInstance().getContext()->dispatchEvent(lifeChangeSerializer);

		getMegaman()->resetHp();
	}
	if (lives == 0)
		Engine::getInstance().markObjectForRemoval(megaman);
}

Megaman* Player::getMegaman() const {
	return megaman;
}

void Player::increasePlayerLives() {
	++lives;
}

void Player::setMegaman(float x, float y) {
	if (megaman == NULL){
		megaman = new Megaman(this, x, y);

		ConnectedPlayerSerializer *connectedPlayerSerializer = new ConnectedPlayerSerializer(megaman);
		connectedPlayerSerializer->setDispatchClient(getId());
		Engine::getInstance().getContext()->dispatchEvent(connectedPlayerSerializer);
	}
}
