/*
 * server_CoordinatesConverter.cpp
 *
 *  Created on: Jun 15, 2016
 *      Author: mastanca
 */

#include "server_CoordinatesConverter.h"

CoordinatesConverter::CoordinatesConverter() {

}

CoordinatesConverter::~CoordinatesConverter() {
}

float CoordinatesConverter::pxToMeters(float x) {
	return convertPxToMeters(x);
}

float CoordinatesConverter::metersToPx(float x) {
	return convertMetersToPx(x);
}
