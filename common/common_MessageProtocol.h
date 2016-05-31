/*
 * common_MessageProtocol.h
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#ifndef COMMON_COMMON_MESSAGEPROTOCOL_H_
#define COMMON_COMMON_MESSAGEPROTOCOL_H_

#define PLAYER_CONNECTED 1       // C -> S
#define NEW_PLAYER 2             // S -> Cs
#define START_GAME 3             // C (admin) -> S -> Cs
#define SEND_MAP 4               // S -> Cs
#define KEY_PRESSED 5            // C -> S
#define UPDATE_MOVEMENTS 6       // S -> Cs
#define OBJECT_CREATED 7         // S -> Cs
#define OBJECT_DESTROYED 8       // S -> Cs
#define HP_CHANGE 9              // S -> C
#define AMMO_CHANGE 10            // S -> C
#define WEAPON_CHANGE 11          // C -> S
#define END_GAME 12               // S -> C
#define LIFE_CHANGE 13            // S -> C


#endif /* COMMON_COMMON_MESSAGEPROTOCOL_H_ */
