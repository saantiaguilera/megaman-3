/*
 * server_FindByPlayerId.h
 *
 *  Created on: May 26, 2016
 *      Author: mastanca
 */

#ifndef SERVER_FUNCTORS_SERVER_FINDBYPLAYERID_H_
#define SERVER_FUNCTORS_SERVER_FINDBYPLAYERID_H_

#include "../game_engine/server_Player.h"

class FindByPlayerId {
	unsigned int id;
public:
	// Constructor
	FindByPlayerId();
	// Destroyer
	virtual ~FindByPlayerId();

	FindByPlayerId(const unsigned int& id) : id(id) {}

    bool operator()(const Player& player) const
        { return player.getId() == id; }
public:
	// Copy constructor
	FindByPlayerId(const FindByPlayerId&);
	// Assignment operator
	FindByPlayerId& operator=(const FindByPlayerId&);
};

#endif /* SERVER_FUNCTORS_SERVER_FINDBYPLAYERID_H_ */
