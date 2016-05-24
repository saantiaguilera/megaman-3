/*
 * common_MessageProtocol.h
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#ifndef COMMON_COMMON_MESSAGEPROTOCOL_H_
#define COMMON_COMMON_MESSAGEPROTOCOL_H_

#define PLAYER_CONNECTED 01       // C -> S
#define NEW_PLAYER 02             // S -> Cs
#define START_GAME 03             // C (admin) -> S -> Cs
#define SEND_MAP 04               // S -> Cs
#define KEY_PRESSED 05            // C -> S
#define UPDATE_MOVEMENTS 06       // S -> Cs
#define OBJECT_CREATED 07         // S -> Cs
#define OBJECT_DESTROYED 08       // S -> Cs
#define HP_CHANGE 09              // S -> C
#define AMMO_CHANGE 10            // S -> C
#define WEAPON_CHANGE 11          // C -> S
#define END_GAME 12               // S -> C
#define LIFE_CHANGE 13            // S -> C


#endif /* COMMON_COMMON_MESSAGEPROTOCOL_H_ */
