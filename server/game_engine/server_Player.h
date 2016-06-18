/*
 * server_Player.h
 *
 *  Created on: May 22, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_PLAYER_H_
#define SERVER_GAME_ENGINE_SERVER_PLAYER_H_

#include <string>

class ClientProxy;
class Megaman;

class Player {
private:
	// Id of the player
	unsigned int id;
	// String identifier of the player, must be set upon connection
	std::string name;
	// When lives reach 0 player is dead
	unsigned int lives;
	// It also has a megaman (could have any character, maybe to me able to play with any)
	Megaman* megaman;
	// The first player to connect is the admin
	bool admin;
public:
	// Constructor
	Player(unsigned int id, const std::string& name, unsigned int initialLives);
	// Destroyer
	virtual ~Player();
	// Current player is admin?
	bool isAdmin() const;
	// Return id of the player
	unsigned int getId() const;
	// Return lives count for current player
	unsigned int getLives() const;
	// Return players name
	const std::string& getName() const;
	// Decrease the players lives by 1
	void decreasePlayerLives();
	// Increase player lives by 1
	void increasePlayerLives();
	// Return my megaman
	Megaman* getMegaman() const;
	// Set the megaman of the player
	void setMegaman(float x, float y);

private:
	// Copy constructor
	Player(const Player&);
	// Assignment operator
	Player& operator=(const Player&);
};

#endif /* SERVER_GAME_ENGINE_SERVER_PLAYER_H_ */
