/*
 * Constants.h
 *
 *  Created on: May 15, 2016
 *      Author: santiago
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define APP_IS_UNIQUE false
#define APP_PACKAGE "com.u.megaslug"
#define APP_NAME "Megaslug"

//TODO THIS ENUMS SHOULD BE SOMEWHERE ELSE

/**
* RESULT_OK : EVERYTHING WAS OK
* RESULT_INDETERMINATE: STILL LOADING OR NO CONNECTION EVER DONE
* RESULT_ERROR: https://www.youtube.com/watch?v=7CNA5rBWzzE
*/
enum ConnectionResult { RESULT_ERROR, RESULT_OK, RESULT_INDETERMINATE };

/**
* Start : Where you put IP : Port
* Lobby : Where the admin selects the map he wants to play
* Game : The map you will play ?
*/
enum Flow { FLOW_START, FLOW_LOBBY, FLOW_GAME };

//Move to another side, this is client side.
#define EVENT_NON_EXISTENT -1
#define EVENT_CREATE_CONNECTION 0
#define EVENT_CONNECTION_ACCEPTED 1
#define EVENT_CONNECTION_REFUSED 2
#define EVENT_CONNECTION_SHUTDOWN 3
#define EVENT_FLOW_START 4
#define EVENT_FLOW_LOBBY 5
#define EVENT_FLOW_GAME 6
#define EVENT_SEND_KEY_MAP 7
#define EVENT_QUIT 8
#define EVENT_START_GAME 9
#define EVENT_PLAYER_CONNECTED 10
#define EVENT_PLAYER_DISCONNECTED 11
#define EVENT_RECEIVED_MAP 12
#define EVENT_SEND_CHANGE_WEAPON 13
#define EVENT_HP_CHANGE 14
#define EVENT_AMMO_CHANGE 15
#define EVENT_LIFE_CHANGE 16

#endif /* CONSTANTS_H_ */
