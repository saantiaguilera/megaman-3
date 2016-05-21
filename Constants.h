/*
 * Constants.h
 *
 *  Created on: May 15, 2016
 *      Author: santiago
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define PACKAGE_NAME "com.u.megaslug"

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

#define EVENT_NON_EXISTENT -1
#define EVENT_CONNECTION_ACCEPTED 1
#define EVENT_CONNECTION_REFUSED 2
#define EVENT_CONNECTION_SHUTDOWN 3
#define EVENT_FLOW_START 4
#define EVENT_FLOW_LOBBY 5
#define EVENT_FLOW_GAME 6

#endif /* CONSTANTS_H_ */
