/*
 * common_MessageProtocol.h
 *
 *  Created on: May 20, 2016
 *      Author: mastanca
 */

#ifndef COMMON_COMMON_MESSAGEPROTOCOL_H_
#define COMMON_COMMON_MESSAGEPROTOCOL_H_

#define PLAYER_CONNECTED 1       // C -> S
/*
CODE - LENGTH - NAME
*/

#define NEW_PLAYER 2             // S -> Cs
/*
CODE - LENGTH - NAME
*/

#define START_GAME 3             // C (admin) -> S -> Cs
/*
CODE - LENGTH - MAPID
*/

#define SEND_MAP 4               // S -> Cs
#define KEY_PRESSED 5            // C -> S
/*
CODE - LENGTH - CHARARRAY WITH KEY PRESSES (0 FALSE 1 TRUE)
*/

#define UPDATE_MOVEMENTS 6       // S -> Cs
#define OBJECT_CREATED 7         // S -> Cs
#define OBJECT_DESTROYED 8       // S -> Cs
#define HP_CHANGE 9              // S -> C
#define AMMO_CHANGE 10            // S -> C
#define WEAPON_CHANGE 11          // C -> S
#define END_GAME 12               // S -> C
#define LIFE_CHANGE 13            // S -> C

#define DISCONNECTED_PLAYER 14
/*
CODE - LENGTH - NAME
*/


#endif /* COMMON_COMMON_MESSAGEPROTOCOL_H_ */
