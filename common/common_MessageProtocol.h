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
C->S: CODE - LENGTH - MAPID
S->C: CODE - LENGTH - JSONMAP
*/

#define SEND_MAP 4               // S -> Cs
#define KEY_PRESSED 5            // C -> S
/*
CODE - LENGTH - CHARARRAY WITH KEY PRESSES (0 FALSE 1 TRUE)
*/

#define UPDATE_MOVEMENTS 6       // S -> Cs
#define OBJECT_CREATED 7         // S -> Cs
/*
CODE - LENGTH - { "id": ID, "type": TYPE, "position": { "x": 5, "y": 8 } }
*/
#define OBJECT_DESTROYED 8       // S -> Cs
/*
CODE - LENGTH - { "id": ID }
*/
#define HP_CHANGE 9              // S -> C
/*
CODE - LENGTH - { "hp": 50 }
*/
#define AMMO_CHANGE 10            // S -> C
/*
CODE - LENGTH - { "ammo": 50, "special": bool }
*/
#define WEAPON_CHANGE 11          // C -> S
/*
CODE - LENGTH - WEAPONID
*/
#define END_GAME 12               // S -> C
/*
CODE - LENGTH (ZERO)
*/
#define LIFE_CHANGE 13            // S -> C
/*
CODE - LENGTH - { "life": 3 }
*/

#define DISCONNECTED_PLAYER 14   // S -> Cs
/*
CODE - LENGTH - NAME
*/


#endif /* COMMON_COMMON_MESSAGEPROTOCOL_H_ */
