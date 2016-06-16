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

float CoordinatesConverter::pxToMeters(float x) {
	std::cout << "pxToMeters for " << x << " is " << x / METERS_TO_PIXELS_RATIO << std::endl;
	return x / METERS_TO_PIXELS_RATIO;
}

float CoordinatesConverter::metersToPx(float x) {
	std::cout << "metersToPx for " << x << " is " << x * METERS_TO_PIXELS_RATIO << std::endl;
	return x * METERS_TO_PIXELS_RATIO;
}
