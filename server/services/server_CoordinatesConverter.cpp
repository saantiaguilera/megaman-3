/*
 * server_CoordinatesConverter.cpp
 *
 *  Created on: Jun 15, 2016
 *      Author: mastanca
 */

#include <iostream>

#include "server_CoordinatesConverter.h"

CoordinatesConverter::CoordinatesConverter() {

}

CoordinatesConverter::~CoordinatesConverter() {
}

float CoordinatesConverter::pxToMeters(float pixels) {
	return pixels * METERS_TO_PIXELS_RATIO;
}

float CoordinatesConverter::metersToPx(float meters) {
	return meters / METERS_TO_PIXELS_RATIO;
}
