/*
 * server_RingTosser.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_RingTosser.h"


RingTosser::~RingTosser() {
}

void RingTosser::fire() {
	--ammo;
}
