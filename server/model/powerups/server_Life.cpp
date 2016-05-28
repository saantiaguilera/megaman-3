/*
 * server_Life.cpp
 *
 *  Created on: May 10, 2016
 *      Author: mastanca
 */

#include "server_Life.h"

Life::Life(float32 x, float32 y) : Powerup(LIFE_DROP_RATE, LIFE_EFFECT_AMOUNT, x, y) {}

Life::~Life() {
}

